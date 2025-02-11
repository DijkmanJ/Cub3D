/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 12:51:36 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/03 17:39:44 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_side_dist(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->player.posx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->player.posx)
			* data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->player.posy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->player.posy)
			* data->deltadisty;
	}
}

void	ft_lineheight(t_data *data)
{
	data->lineheight = (int)(data->window_height / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + data->window_height / 2;
	if (data->drawstart < 0 || data->drawstart > 1000)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + data->window_height / 2;
	if (data->drawend >= data->window_height || data->drawend < 0)
		data->drawend = data->window_height - 1;
}

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	index = (y * texture->width + x) * 4;
	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_step_for_check(t_data *data, int x)
{
	data->camerax = 2 * x / (double)data->window_width - 1;
	data->raydirx = data->player.dirx + data->player.planex * data->camerax;
	data->raydiry = data->player.diry + data->player.planey * data->camerax;
	data->mapx = (int)data->player.posx;
	data->mapy = (int)data->player.posy;
	if (data->raydirx == 0)
		data->deltadistx = 1e30;
	else
		data->deltadistx = fabs(1 / data->raydirx);
	if (data->raydiry == 0)
		data->deltadisty = 1e30;
	else
		data->deltadisty = fabs(1 / data->raydiry);
	data->hit = false;
}

void	render_frame(t_data *data)
{
	int		x;
	double	angle;

	x = 0;
	angle = 0;
	ft_memset(data->blocks->pixels, 0x00000000, 220 * 220 * sizeof(uint32_t));
	draw_cursor(data, angle);
	minimap(data);
	ft_memset(data->img->pixels, 0x000000FF,
		WINDOW_H * WINDOW_W * sizeof(uint32_t));
	while (x < WINDOW_W)
	{
		get_step_for_check(data, x);
		calc_side_dist(data);
		ft_dda(data);
		ft_lineheight(data);
		draw_line(data, x);
		x++;
	}
}
