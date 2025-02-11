/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 13:08:41 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/10/07 16:50:51 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WINDOW_W 1000
# define WINDOW_H 1000
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MAP_CELL_SIZE 20
# define M_PI_2	1.5707963267948966
# define BLUE 0x87CEEB
# define GREEN 0x228B22
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define ROT_SPEED 0.03
# define WALL_PADDING 0.3
# define MOUSE_SENS 30

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>

# include "./MLX42/include/glad/glad.h"
# include "./MLX42/include/KHR/khrplatform.h"
# include "./MLX42/include/lodepng/lodepng.h"
# include "./MLX42/include/MLX42/MLX42_Int.h"
# include "libft/libft.h"

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_player;

typedef struct s_data
{
	//parsing
	mlx_texture_t	**textures;
	mlx_texture_t	**extra_textures;
	char			**texture_paths;
	char			**map_txt;
	int				map_height;
	char			orientation;
	int				yposition;
	int				xposition;
	//event handler
	double			newposx;
	double			newposy;
	double			move_speed;
	//raycasting
	mlx_texture_t	*tex;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	bool			hit;
	bool			side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	char			**map;
	//textures
	uint32_t		floor;
	uint32_t		sky;
	mlx_image_t		*img;
	mlx_image_t		*minimap;
	mlx_image_t		*blocks;
	mlx_image_t		*cursor;
	mlx_image_t		*intervention;
	double			wallx;
	int				texx;
	//mlx
	void			*mlx;
	int				bpp;
	int				size_line;
	int				window_width;
	int				window_height;
	int				endian;
	t_player		player;
}	t_data;

typedef struct t_map
{
	int				x;
	int				y;
	int				y_begin;
	int				y_end;
	int				x_begin;
	int				x_end;
	double			offset_x;
	double			offset_y;
	uint32_t		color;
}	t_map;

//cleanup.c
void			ft_exit(t_data *data, char *msg);
void			free_pointer_array_part(void **ptr_arr, int i);
void			free_pointer_array(void **prt_arr);
void			delete_textures(mlx_texture_t **textures, int size);

//draw.c
void			draw_floor(t_data *data, int x);
void			draw_sky(t_data *data, int x);
void			draw_line(t_data *data, int x);
int				check_double_newlines(char *map);

//event_handler_utils.c
int				is_collision(t_data *data, double new_pos_x, double new_pos_y);
void			get_movement_input(t_data *data,
					double *move_x, double *move_y);
void			get_movement_input2(t_data *data, double *strafe_x,
					double *strafe_y);

//event_handler.c
void			rotate_cam(t_data *data, int dir);
void			move_player(t_data *data, double x, double y);
int				is_collision(t_data *data, double newPosX, double newPosY);
void			movement_input_handler(t_data *data,
					double new_pos_x, double new_pos_y);
void			mouse_movement_handler(t_data *data);
void			key_input_handler(t_data *data);

//init_structs.c
mlx_texture_t	**load_png(char **texture_paths);
mlx_texture_t	**load_extra_png(t_data *data);
int				init_images(t_data *data);
void			init_data_struct(t_data *data);
void			init_player(t_data *data);

//main.c
void			images_to_window(t_data *data);
int				check_double_newlines(char *map);
int				parse_map_data(t_data *data, int argc, char **argv);
void			images_to_window(t_data *data);

//map_validation.c
bool			ft_checkspace_up_down(char **map, int y, int x, int height);
int				ft_checkborders(char **map, int height);
int				ft_checkspaces(char **map, int height);
int				ft_checkstartpos(t_data *data, int y);

//minimap.c
uint32_t		get_pixel_color(mlx_image_t *image, int x, int y);
void			draw_tile(t_data *data, t_map *map, int x, int y);
int				map_range(t_data *data, t_map *map);
void			draw_cursor(t_data *data, double angle);
void			minimap(t_data *data);

//parsing_map.c
int				get_height(char **map);
char			**create_map(t_data *data);
char			**create_map_arr(char *map);
int				check_textures(t_data *data);
void			fill_textures(t_data *data, char **pair);

//parsing.c
int				parse_textures(t_data *data);
int				ft_isnbr(char *str);
uint32_t		parse_color(char *color_string);

//raycasting_utils.c
void			get_tex_coordinate(t_data *data);
void			get_perp_wall_dist(t_data *data);
void			x_axe_intersect(t_data *data);
void			y_axe_intersect(t_data *data);
void			ft_dda(t_data *data);

//raycasting.c
void			ft_calc_sideDist(t_data *data);
void			ft_lineheight(t_data *data);
uint32_t		get_texture_pixel(mlx_texture_t *texture, int x, int y);
void			get_step_for_check(t_data *data, int x);
void			render_frame(t_data *data);

#endif
