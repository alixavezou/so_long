/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:55 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/04 16:54:33 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>

typedef struct	s_data t_data;
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
	int			map_size;
	int			total_nb_line;
	int			total_nb_col;
	int			collected_items;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collectibles_items;
	int			total_collectibles;
	int			compteur_of_moves;
	int			row;
	int			col;
	int			is_valid_path;
	int 		found_exit;

	char		**map;
	char		**map_cpy;
	char		**map_new;
	char		*file_name;
};

//KEYCODE
# define ESC 53
# define GO_UP 126//119
# define GO_DOWN 125//115
# define GO_LEFT 123//97
# define GO_RIGHT 124//100
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

//MAPS ELEMENTS
# define ITEMS_IMAGE "images/ball.xpm"
# define PLAYER_IMAGE "images/player.xpm"
# define EXIT_IMAGE "images/goal.xpm"
# define EMPTY_IMAGE "images/grass.xpm"
# define WALLS_IMAGE "images/wall.xpm"

size_t	ft_strlen(char *str);

void	ft_init_map(t_data *so_long);
void	ft_recup_map_size(t_data *data);
void	ft_columns_size(t_data *data);
void	ft_place_xpm(t_data *data);
void	file_error(t_data *data);
void	ft_print_walls(t_data env);
void	ft_insidemap(t_data *data);
void	ft_get_player_position(t_data *data);
void	ft_handle_exit(t_data *data);
void	ft_map(t_data *data);
void	ft_free_map(char **map);

int		key_hook(int keycode, t_data *data);
int		handle_no_event(void *data);
int		ft_checkendofline(char *buffer_save);
int		ft_check_walls(t_data *data);
int		ft_check_map(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_collected_items(t_data *data);
int		ft_backtrack(int row, int col, t_data *data);

char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_print_map(t_data *data);
char	*ft_print_line(char *buffer_save);
char	*ft_get_buffer_save(char *buffer_save);
char	*ft_read(int fd, char *buffer_read);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
