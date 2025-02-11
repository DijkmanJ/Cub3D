/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 11:33:36 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/03 17:31:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_texture_t	**load_png(char **texture_paths)
{
	mlx_texture_t	**textures;
	int				i;

	i = 0;
	textures = malloc(sizeof(mlx_texture_t *) * 5);
	if (!textures)
		return (printf("malloc failed in load png"), NULL);
	while (i < 4)
	{
		textures[i] = mlx_load_png(texture_paths[i]);
		if (textures[i] == NULL)
			return (delete_textures(textures, i), NULL);
		i++;
	}
	textures[i] = NULL;
	return (textures);
}

mlx_texture_t	**load_extra_png(t_data *data)
{
	mlx_texture_t	**extra_textures;
	char			*paths[3];
	int				i;

	paths[0] = "./textures/intervention.png";
	paths[1] = "./textures/map.png";
	paths[2] = "./textures/cursor.png";
	i = 0;
	extra_textures = malloc(sizeof(mlx_texture_t *) * 4);
	if (!extra_textures)
		ft_exit(data, "malloc failed in load_extra_png");
	while (i < 3)
	{
		extra_textures[i] = mlx_load_png(paths[i]);
		if (!extra_textures[i])
			return (delete_textures(extra_textures, i), NULL);
		i ++;
	}
	extra_textures[i] = NULL;
	return (extra_textures);
}

int	init_images(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	if (!data->img)
		ft_exit(data, "mlx_new_image failed");
	data->textures = load_png(data->texture_paths);
	if (!data->textures)
		ft_exit(data, "ERROR when loading textures\n");
	data->extra_textures = load_extra_png(data);
	if (!data->extra_textures)
		ft_exit(data, "extra textures failed");
	data->intervention
		= mlx_texture_to_image(data->mlx, data->extra_textures[0]);
	data->minimap = mlx_texture_to_image(data->mlx, data->extra_textures[1]);
	data->cursor = mlx_new_image(data->mlx, 220, 220);
	images_to_window(data);
	return (0);
}

void	init_data_struct(t_data *data)
{
	data->map = NULL;
	data->map_txt = NULL;
	data->mlx = NULL;
	data->orientation = '\0';
	data->window_width = WINDOW_W;
	data->window_height = WINDOW_H;
	data->textures = NULL;
	data->extra_textures = NULL;
	data->texture_paths = calloc(sizeof(char *), 7);
	if (!data->texture_paths)
	{
		free(data);
		exit(1);
	}
	data->move_speed = 0.3;
}

void	init_player(t_data *data)
{
	data->player.dirx = 0;
	data->player.diry = 0;
	data->player.planey = 0;
	data->player.planex = 0;
	if (data->orientation == 'N')
	{
		data->player.diry = -1;
		data->player.planex = 0.66;
	}
	else if (data->orientation == 'E')
	{
		data->player.dirx = 1;
		data->player.planey = 0.66;
	}
	else if (data->orientation == 'S')
	{
		data->player.diry = 1;
		data->player.planex = -0.66;
	}
	else if (data->orientation == 'W')
	{
		data->player.dirx = -1;
		data->player.planey = -0.66;
	}
}
