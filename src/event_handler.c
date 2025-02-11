/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 11:31:36 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/03 17:30:14 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_cam(t_data *data, int dir)
{
	float	move_dir;
	double	old_dirx;
	double	old_planex;

	move_dir = ROT_SPEED * dir;
	old_dirx = data->player.dirx;
	old_planex = data->player.planex;
	data->player.dirx
		= data->player.dirx * cos(move_dir) - data->player.diry * sin(move_dir);
	data->player.diry
		= old_dirx * sin(move_dir) + data->player.diry * cos(move_dir);
	data->player.planex
		= data->player.planex * cos(move_dir) - data->player.planey
		* sin(move_dir);
	data->player.planey
		= old_planex * sin(move_dir) + data->player.planey * cos(move_dir);
}

void	move_player(t_data *data, double x, double y)
{
	data->player.posx += x;
	data->player.posy += y;
}

void	movement_input_handler(t_data *data, double new_pos_x, double new_pos_y)
{
	double	move_x;
	double	move_y;
	double	strafe_x;
	double	strafe_y;

	get_movement_input(data, &move_x, &move_y);
	get_movement_input2(data, &strafe_x, &strafe_y);
	new_pos_x = data->player.posx + move_x + strafe_x;
	new_pos_y = data->player.posy + move_y + strafe_y;
	if (!is_collision(data, new_pos_x, new_pos_y))
		move_player(data, move_x + strafe_x, move_y + strafe_y);
	else
	{
		if (!is_collision(data, data->player.posx, new_pos_y))
			move_player(data, 0, move_y + strafe_y);
		if (!is_collision(data, new_pos_x, data->player.posy))
			move_player(data, move_x + strafe_x, 0);
	}
}

void	mouse_movement_handler(t_data *data)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	int32_t	mouse_speed;

	mouse_speed = 0;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	if (mouse_x > 500)
	{
		mouse_speed = mouse_x - 500;
		while (mouse_speed > 0)
		{
			rotate_cam(data, 1);
			mouse_speed -= MOUSE_SENS;
		}
	}
	if (mouse_x < 500)
	{
		mouse_speed = 500 - mouse_x;
		while (mouse_speed > 0)
		{
			rotate_cam(data, -1);
			mouse_speed -= MOUSE_SENS;
		}
	}
	mlx_set_mouse_pos(data->mlx, 500, 500);
}

void	key_input_handler(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = 0.0;
	new_pos_y = 0.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_cam(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_cam(data, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		data->move_speed = 0.1;
	else
		data->move_speed = 0.05;
	movement_input_handler(data, new_pos_x, new_pos_y);
}
