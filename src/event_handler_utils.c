/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/02 15:30:35 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/03 17:26:45 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_collision(t_data *data, double new_pos_x, double new_pos_y)
{
	int	mapx;
	int	mapy;

	mapx = (int)new_pos_x;
	mapy = (int)new_pos_y;
	if (data->map[mapy][mapx] == '1')
		return (1);
	if (data->map[(int)(new_pos_y - WALL_PADDING)][mapx] == '1' ||
		data->map[(int)(new_pos_y + WALL_PADDING)][mapx] == '1' ||
		data->map[mapy][(int)(new_pos_x - WALL_PADDING)] == '1' ||
		data->map[mapy][(int)(new_pos_x + WALL_PADDING)] == '1')
		return (1);
	return (0);
}

void	get_movement_input(t_data *data, double *move_x, double *move_y)
{
	*move_x = 0;
	*move_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		*move_x = data->player.dirx * data->move_speed;
		*move_y = data->player.diry * data->move_speed;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		*move_x = -data->player.dirx * data->move_speed;
		*move_y = -data->player.diry * data->move_speed;
	}
}

void	get_movement_input2(t_data *data, double *strafe_x, double *strafe_y)
{
	*strafe_x = 0;
	*strafe_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		*strafe_x = -data->player.planex * data->move_speed;
		*strafe_y = -data->player.planey * data->move_speed;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		*strafe_x = data->player.planex * data->move_speed;
		*strafe_y = data->player.planey * data->move_speed;
	}
}
