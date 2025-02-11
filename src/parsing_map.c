/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 16:31:38 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/07 16:15:52 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->texture_paths[i] == NULL)
		{
			i = 0;
			while (i < 6)
			{
				if (data->texture_paths[i])
					free(data->texture_paths[i]);
				i ++;
			}
			return (free(data->texture_paths), 1);
		}
		i ++;
	}
	return (0);
}

void	fill_textures(t_data *data, char **pair)
{
	if (!ft_strncmp(pair[0], "NO", ft_strlen(pair[0])))
		data->texture_paths[0] = ft_strdup(pair[1]);
	if (!ft_strncmp(pair[0], "SO", ft_strlen(pair[0])))
		data->texture_paths[1] = ft_strdup(pair[1]);
	if (!ft_strncmp(pair[0], "WE", ft_strlen(pair[0])))
		data->texture_paths[2] = ft_strdup(pair[1]);
	if (!ft_strncmp(pair[0], "EA", ft_strlen(pair[0])))
		data->texture_paths[3] = ft_strdup(pair[1]);
	if (!ft_strncmp(pair[0], "F", ft_strlen(pair[0])))
		data->texture_paths[4] = ft_strdup(pair[1]);
	if (!ft_strncmp(pair[0], "C", ft_strlen(pair[0])))
		data->texture_paths[5] = ft_strdup(pair[1]);
}

int	get_height(char **map)
{
	int	height;

	height = 0;
	if (!map)
		return (0);
	while (map[height])
		height ++;
	return (height);
}

char	**create_map(t_data *data)
{
	int		i;
	int		height;
	char	**map;

	i = 6;
	height = 0;
	while (data->map_txt[i + height])
		height ++;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		ft_exit(data, "malloc failed in create map");
	map[height] = NULL;
	height --;
	while (height >= 0)
	{
		map[height] = ft_strdup(data->map_txt[i + height]);
		if (!map[height])
		{
			free_pointer_array_part((void **)map, height);
			ft_exit(data, "ft_strdup failed in create_map");
		}
		height --;
	}
	map[data->yposition][data->xposition] = '0';
	return (map);
}

char	**create_map_arr(char *map)
{
	char	*string;
	char	*new_string;
	char	temp[2];
	int		fd;
	char	**array;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (printf("No such file or Directory"), NULL);
	string = calloc(1, 1);
	if (!string)
		return (printf("calloc failed in create map arr"), close(fd), NULL);
	while ((read(fd, temp, 1) > 0))
	{
		temp[1] = '\0';
		new_string = ft_strjoin(string, temp);
		string = new_string;
	}
	close(fd);
	if (check_double_newlines(string))
		return (printf("double new lines in map"), free(string), NULL);
	array = ft_split(string, '\n');
	free(string);
	return (array);
}
