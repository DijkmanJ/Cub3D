/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 17:04:57 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/10/09 12:13:43 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sky(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->drawstart)
	{
		mlx_put_pixel(data->img, x, y, data->sky);
		y ++;
	}
}

void	draw_floor(t_data *data, int x)
{
	while (data->drawend < WINDOW_H)
	{
		mlx_put_pixel(data->img, x, data->drawend, data->floor);
		data->drawend ++;
	}
}

void	draw_line(t_data *data, int x)
{
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;

	draw_sky(data, x);
	step = 1.0 * TEX_HEIGHT / data->lineheight;
	tex_pos = (data->drawstart - data->window_height / 2 + data->lineheight / 2)
		* step;
	while (data->drawstart < data->drawend)
	{
		tex_y = (int)tex_pos % TEX_HEIGHT;
		tex_pos += step;
		color = get_texture_pixel(data->tex, data->texx, tex_y);
		mlx_put_pixel(data->img, x, data->drawstart, color);
		data->drawstart ++;
	}
	draw_floor(data, x);
}

int	start_map(char *map, int i)
{
	bool	one;

	one = false;
	while (map[i] == '1' || map[i] == ' ' || map[i] == '\t')
	{
		if (map[i] == '1')
			one = true;
		if (map[i + 1] == '\n' && one)
			return (1);
		i ++;
	}
	return (0);
}

int	check_double_newlines(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && start_map(map, i + 1))
			break ;
		i ++;
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			while (map[i] == '\n' || map[i] == ' ' || map[i] == '\t')
			{
				if (map[i + 1] == '\0')
					return (0);
				i ++;
			}
			return (1);
		}
		i ++;
	}
	return (0);
}
