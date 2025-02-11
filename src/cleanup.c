/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 14:35:19 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/08 14:11:21 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_exit(t_data *data, char *msg)
{
	if (data->map)
		free_pointer_array((void **)data->map);
	if (data->map_txt)
		free_pointer_array((void **)data->map_txt);
	if (data->texture_paths)
		free_pointer_array((void **)data->texture_paths);
	if (data->textures)
		delete_textures(data->textures, 4);
	if (data->extra_textures)
		delete_textures(data->extra_textures, 3);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free(data);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	free_pointer_array_part(void **ptr_arr, int i)
{
	while (i > 0)
	{
		free(ptr_arr[i - 1]);
		i --;
	}
	free(ptr_arr);
}

void	free_pointer_array(void **prt_arr)
{
	int	i;

	i = 0;
	while (prt_arr[i])
	{
		free(prt_arr[i]);
		i ++;
	}
	free(prt_arr);
}

void	delete_textures(mlx_texture_t **textures, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_delete_texture(textures[i]);
		i ++;
	}
	free(textures);
}
