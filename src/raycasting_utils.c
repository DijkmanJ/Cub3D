/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 17:05:45 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/10/07 13:07:42 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_tex_coordinate(t_data *data)
{
	if (!data->side)
		data->wallx = data->player.posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->player.posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor(data->wallx);
	data->texx = (int)(data->wallx * (double)TEX_WIDTH);
	if ((!data->side && data->raydirx > 0) || (data->side && data->raydiry < 0))
		data->texx = TEX_WIDTH - data->texx - 1;
}

void	get_perp_wall_dist(t_data *data)
{
	if (!data->side)
		data->perpwalldist = (data->sidedistx - data->deltadistx);
	else
		data->perpwalldist = (data->sidedisty - data->deltadisty);
}

void	x_axe_intersect(t_data *data)
{
	data->sidedisty += data->deltadisty;
	data->mapy += data->stepy;
	data->side = true;
	if (data->raydiry > 0)
		data->tex = data->textures[0];
	else
		data->tex = data->textures[1];
}

void	y_axe_intersect(t_data *data)
{
	data->sidedistx += data->deltadistx;
	data->mapx += data->stepx;
	data->side = false;
	if (data->raydirx > 0)
		data->tex = data->textures[2];
	else
		data->tex = data->textures[3];
}

void	ft_dda(t_data *data)
{
	while (!data->hit)
	{
		if (data->sidedistx < data->sidedisty)
			y_axe_intersect(data);
		else
			x_axe_intersect(data);
		if (data->map[data->mapy][data->mapx] == '1')
			data->hit = true;
	}
	get_perp_wall_dist(data);
	get_tex_coordinate(data);
}
