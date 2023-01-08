/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:55 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:23:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_data	t_data;
struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_wall;
	void		*mlx_collectible;
	void		*mlx_player;
	void		*mlx_exit;
	void		*mlx_empty;
	void		*mlx_items;

	int			x;
	int			y;
	int			wall_x;
	int			wall_y;
	int			map_size;
	int			total_nb_line;
	int			total_nb_col;
	int			collected_items;
	int			collectible_items;
	int			player;
	int			sortie;
	int			collectible;
	int			empty;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			compteur_of_moves;
	int			row;
	int			col;
	int			is_valid_path;
	int			found_exit;

	char		**map;
	char		**map_cpy;
	char		*file_name;
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//KEYCODE
# define ESC 65307
# define CROSS 17
# define GO_UP 65362
# define GO_DOWN 65364
# define GO_LEFT 65361
# define GO_RIGHT 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

//MAPS ELEMENTS
# define ITEM_IMG "images/ball.xpm"
# define PLAYER_IMG "images/player.xpm"
# define EXIT_IMG "images/goal.xpm"
# define EMPTY_IMG "images/grass.xpm"
# define WALLS_IMG "images/wall.xpm"

void	ft_recup_map_size(t_data *data);
void	ft_columns_size(t_data *data);
void	ft_place_xpm(t_data *data);
void	ft_load_images(t_data *data);
void	ft_file_error(t_data *data);
void	ft_insidemap(t_data *data);
void	ft_get_player_position(t_data *data);
void	ft_handle_exit(t_data *data);
void	ft_free_map(char **map);
void	ft_initialize_values(t_data *data, char *filename);
void	ft_check_player(t_data *data, int i, int j);
void	ft_check_sortie(t_data *data, int i, int j);
void	ft_check_empty_space(t_data *data, int i, int j);
void	ft_check_items(t_data *data, int i, int j);
void	ft_check_map_is_complete(t_data *data);
void	ft_check_valid_path(t_data *data);
void	ft_check_x_walls(t_data *data);
void	ft_check_walls_bottom(t_data *data, int size);
void	ft_check_y_walls(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_up(t_data *data);
void	ft_init_map(t_data *data);
void	ft_allocate_maps(t_data *data, int nb_line);
void	ft_initialize_maps(t_data *data, int nb_line);
void	ft_destroy_image(t_data *data);

int		key_hook(int keycode, t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_map(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_backtrack(int row, int col, t_data *data);
int		ft_backtrack_part_1(int row, int col, t_data *data);
int		ft_backtrack_part_2(int row, int col, t_data *data);
int		ft_draw_wall(t_data *data, int i, int j);
int		ft_draw_player(t_data *data, int i, int j);
int		ft_draw_exit(t_data *data, int i, int j);
int 	ft_draw_empty(t_data *data, int i, int j);
int 	ft_draw_item(t_data *data, int i, int j);
int		ft_check_if_map_is_empty(t_data *data);
int		init_window(t_data *data);
int		ft_close(t_data *data);
int		ft_get_nbr_col(char *str);

#endif
