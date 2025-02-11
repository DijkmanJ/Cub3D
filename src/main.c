/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 12:57:11 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/08 14:18:21 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	images_to_window(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		ft_exit(data, "Error in image to window\n");
	if (mlx_image_to_window(data->mlx, data->intervention, 175, 0) == -1)
		ft_exit(data, "Error in image to window\n");
	if (mlx_image_to_window(data->mlx, data->minimap, (0.05 * WINDOW_W),
			WINDOW_H - 200 - (0.05 * WINDOW_H)) == -1)
		ft_exit(data, "Error in image to window\n");
	data->blocks = mlx_new_image(data->mlx, 220, 220);
	if (!data->blocks)
		ft_exit(data, "Error in new image");
	if (mlx_image_to_window(data->mlx, data->blocks, (0.05 * WINDOW_W), WINDOW_H
			- 200 - (0.05 * WINDOW_H)) == -1)
		ft_exit(data, "Error in image to window\n");
	if (mlx_image_to_window(data->mlx, data->cursor, (0.05 * WINDOW_W), WINDOW_H
			- 200 - (0.05 * WINDOW_H)) == -1)
		ft_exit(data, "Error in image to window\n");
}

int	parse_map_data(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (ft_exit(data, "invalid argc"), 1);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
		return (ft_exit(data, "invalid map type"), 1);
	data->map_txt = create_map_arr(argv[1]);
	if (!data->map_txt)
		return (1);
	if (parse_textures(data))
		return (1);
	data->map_height = get_height(data->map_txt);
	if (ft_checkborders(data->map_txt, data->map_height))
		return (1);
	if (ft_checkspaces(data->map_txt, data->map_height))
		return (1);
	if (ft_checkstartpos(data, 6))
		return (1);
	data->floor = parse_color(data->texture_paths[4]);
	if (!data->floor)
		ft_exit(data, "fail in parse_color");
	data->sky = parse_color(data->texture_paths[5]);
	if (!data->sky)
		ft_exit(data, "fail in parse_color");
	data->map = create_map(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data_struct(data);
	if (parse_map_data(data, argc, argv))
		ft_exit(data, "");
	data->mlx = mlx_init(WINDOW_W, WINDOW_H, "cub3d", false);
	if (!data->mlx)
		ft_exit(data, "failed to initialize MLX");
	init_player(data);
	data->player.posx = data->xposition + 0.5;
	data->player.posy = data->yposition + 0.5;
	init_images(data);
	mlx_set_mouse_pos(data->mlx, 500, 500);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(data->mlx, (void *) key_input_handler, data);
	mlx_loop_hook(data->mlx, (void *) render_frame, data);
	mlx_cursor_hook(data->mlx, (void *) mouse_movement_handler, data);
	mlx_loop(data->mlx);
	ft_exit(data, "Succes!\n");
	return (0);
}
