/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 16:51:41 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/10/08 13:53:36 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_identifiers(char *pair)
{
	if (!ft_strncmp(pair, "NO", ft_strlen(pair) + 1))
		return (0);
	if (!ft_strncmp(pair, "SO", ft_strlen(pair) + 1))
		return (0);
	if (!ft_strncmp(pair, "WE", ft_strlen(pair) + 1))
		return (0);
	if (!ft_strncmp(pair, "EA", ft_strlen(pair) + 1))
		return (0);
	if (!ft_strncmp(pair, "F", ft_strlen(pair) + 1))
		return (0);
	if (!ft_strncmp(pair, "C", ft_strlen(pair) + 1))
		return (0);
	return (1);
}

int	parse_textures(t_data *data)
{
	int		i;
	char	**pair;

	i = 0;
	while (i < 6)
	{
		pair = ft_split(data->map_txt[i], ' ');
		if (!pair || get_height(pair) != 2 || parse_identifiers(pair[0]))
		{
			free_pointer_array_part((void **)data->texture_paths, i);
			data->texture_paths = NULL;
			if (pair)
				free_pointer_array((void **)pair);
			ft_exit(data, "parse textures failed");
		}
		fill_textures(data, pair);
		free_pointer_array((void **)pair);
		i ++;
	}
	if (check_textures(data))
		ft_exit(data, "malloc failed in fill textures");
	data->texture_paths[i] = NULL;
	return (0);
}

int	ft_isnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i ++;
	}
	return (0);
}

uint32_t	parse_color(char *color_string)
{
	char		**color;
	uint32_t	result;
	int			r;
	int			g;
	int			b;

	color = ft_split(color_string, ',');
	if (!color)
		return (perror("mallocfail"), 0);
	if (get_height(color) != 3)
		return (free_pointer_array((void **)color), 0);
	if (ft_isnbr(color[0]) || ft_isnbr(color[1]) || ft_isnbr(color[2]))
		return (free_pointer_array((void **)color), printf("invalid"), 0);
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (free_pointer_array((void **)color), 0);
	result = ((r << 24) | (g << 16) | (b << 8) | 0xFF);
	free_pointer_array((void **)color);
	return (result);
}
