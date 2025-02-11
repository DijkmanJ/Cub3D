/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 12:57:11 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/07 14:39:36 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_checkspace_up_down(char **map, int y, int x, int height)
{
	if (y > 6 && y < height - 1 && (((int)ft_strlen(map[y - 1]) > x
				&& map[y - 1][x] != ' ' && map[y - 1][x] != '1')
				|| ((int)ft_strlen(map[y + 1]) > x
				&& map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
		return (false);
	if (y == 6 && (int)ft_strlen(map[y + 1]) > x
		&& map[y + 1][x] != ' ' && map[y + 1][x] != '1')
		return (false);
	if (y == height - 1 && (int)ft_strlen(map[y - 1]) > x
		&& map[y - 1][x] != ' ' && map[y - 1][x] != '1')
		return (false);
	return (true);
}

int	ft_checkborders(char **map, int height)
{
	int	x;
	int	y;

	y = 6;
	while (map[y])
	{
		x = 0;
		if (map[y][ft_strlen(map[y]) - 1] != '1')
			return (printf("invalid borders\n"), 1);
		while (map[y][x] != '\0')
		{
			if (y == 6 || y == height - 1)
			{
				if (map[y][x] != ' ' && map[y][x] != '1')
					return (printf("invalid borders\n"), 1);
			}
			if (map[y][0] != ' ' && map[y][0] != '1')
				return (printf("invalid borders\n"), 1);
			x ++;
		}
		y ++;
	}
	return (0);
}

int	ft_checkspaces(char **map, int height)
{
	int	x;
	int	y;

	y = 6;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			while (map[y][x] == ' ')
			{
				if (!ft_checkspace_up_down(map, y, x, height))
					return (printf("invalid border\n"), 1);
				x ++;
				if (x != 0 && map[y][x - 1] != ' ' && map[y][x - 1] != '1')
					return (printf("invalid borders\n"), 1);
				if (map[y][x] != ' ' && map[y][x] != '1')
					return (printf("invalid borders\n"), 1);
			}
			x ++;
		}
		y ++;
	}
	return (0);
}

int	ft_checkstartpos(t_data *data, int y)
{
	int	x;

	while (data->map_txt[y])
	{
		x = 0;
		while (data->map_txt[y][x])
		{
			if (!ft_strchr(" 01NSWE", data->map_txt[y][x]))
				return (printf("invalid char in map\n"), 1);
			if (ft_strchr("NSWE", data->map_txt[y][x]))
			{
				if (data->orientation != '\0')
					return (printf("multiple players in map\n"), 1);
				data->orientation = data->map_txt[y][x];
				data->yposition = y - 6;
				data->xposition = x;
			}
			x ++;
		}
		y ++;
	}
	if (data->orientation != '\0')
		return (0);
	return (printf("invalid starting pos\n"), 1);
}
