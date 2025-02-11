/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 11:38:07 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/10/07 13:39:11 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	get_pixel_color(mlx_image_t *image, int x, int y)
{
	int			index;
	uint32_t	color;

	if (x < 0 || (uint32_t)x >= image->width || (uint32_t)y < 0
		|| (uint32_t)y >= image->height)
		return (0);
	index = (y * image->width + x) * 4;
	color = *(uint32_t *)&image->pixels[index];
	return (color);
}

void	draw_tile(t_data *data, t_map *map, int x, int y)
{
	int	y_begin;
	int	y_end;
	int	x_begin;
	int	x_end;

	y_end = y + MAP_CELL_SIZE - 2;
	x_begin = x + 2;
	x_end = x + MAP_CELL_SIZE - 2;
	while (x_begin <= x_end)
	{
		y_begin = y + 2;
		while (y_begin <= y_end)
		{
			if (y < 220 && x < 220 && get_pixel_color
				(data->minimap, x_begin, y_begin) == 0xFF505050)
				mlx_put_pixel(data->blocks, x_begin, y_begin, map->color);
			y_begin ++;
		}
		x_begin ++;
	}
}

int	map_range(t_data *data, t_map *map)
{
	if ((map->y_begin >= 0 && map->y_begin < data->map_height - 6)
		&& (map->x_begin >= 0 && map->x_begin
			< (int)ft_strlen(data->map[map->y_begin])))
	{
		if (data->map[map->y_begin][map->x_begin] == '1')
		{
			map->color = BLUE;
			return (1);
		}
		if (data->map[map->y_begin][map->x_begin] == '0')
		{
			map->color = GREEN;
			return (1);
		}
	}
	return (0);
}

void	draw_cursor(t_data *data, double ang)
{
	int			x;
	int			y;
	int			rot_x;
	int			rot_y;
	uint32_t	color;

	y = 80;
	ft_memset(data->cursor->pixels, 0x00000000, 220 * 220 * sizeof(uint32_t));
	ang = atan2(data->player.diry, data->player.dirx) + M_PI_2;
	while (y < 115)
	{
		x = 100;
		while (x < 120)
		{
			color = get_texture_pixel(data->extra_textures[2], x, y);
			rot_x = (int)((x - 110) * cos(ang) - (y - 110) * sin(ang) + 110);
			rot_y = (int)((x - 110) * sin(ang) + (y - 110) * cos(ang) + 110);
			if (color != 0x00000000)
				mlx_put_pixel(data->cursor, rot_x, rot_y, color);
			x++;
		}
		y++;
	}
}

void	minimap(t_data *data)
{
	t_map	map;

	map.y = 0;
	map.y_begin = (int)data->player.posy - 5;
	map.y_end = (int)data->player.posy + 6;
	map.x_end = (int)data->player.posx + 6;
	map.offset_x = data->player.posx - floor(data->player.posx);
	map.offset_y = data->player.posy - floor(data->player.posy);
	map.y = -map.offset_y * MAP_CELL_SIZE;
	while (map.y_begin <= map.y_end)
	{
		map.x = -map.offset_x * MAP_CELL_SIZE;
		map.x_begin = (int)data->player.posx - 5;
		while (map.x_begin <= map.x_end)
		{
			if (map_range(data, &map))
				draw_tile(data, &map, map.x + (MAP_CELL_SIZE / 2),
					map.y + (MAP_CELL_SIZE / 2));
			map.x += MAP_CELL_SIZE;
			map.x_begin ++;
		}
		map.y_begin ++;
		map.y += MAP_CELL_SIZE;
	}
}
