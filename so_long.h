/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:55 by aavezou           #+#    #+#             */
/*   Updated: 2022/11/07 18:35:48 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx/mlx.h"
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

typedef struct	s_data t_data;
struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_wall;
	void		*mlx_collectible;
	void		*mlx_player;
	void		*mlx_exit;
	void		*mlx_empty;
	void		*mlx_items;
	void		*mlx_win2;

	int			x; //case de mon player (on enregistre sa position)
	int			y; //ligne de mon player
	int			map_size;
	int			total_nb_line;
	int			total_nb_col;

	char		**map;
	char		**map_new;
	char		*file_name;
};

//KEYCODE
# define ESC 53
# define GO_UP 87//119
# define GO_DOWN 83//115
# define GO_LEFT 65//97
# define GO_RIGHT 124//100

//MAPS ELEMENTS
# define ITEMS_IMAGE "collectible.xpm"
# define PLAYER_IMAGE "player.xpm"
# define EXIT_IMAGE "exit.xpm"
# define EMPTY_IMAGE "empty.xpm"
# define WALLS_IMAGE "walls.xpm"

size_t	ft_strlen(char *str);

void 	ft_init_map(t_data *so_long);
void	ft_recup_map_size(t_data *data);
void	ft_columns_size(t_data *data);
void	ft_place_xpm(t_data *data);
void	file_error(t_data *data);
void	ft_print_walls(t_data env);
void	ft_insidemap(t_data *data);
void	ft_get_player_position(t_data *data);


int		key_hook(int keycode, t_data *data);
int		handle_no_event(void *data);
int		ft_checkendofline(char *buffer_save);
int		ft_check_walls(t_data *data);
int		ft_check_map(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_print_map(t_data *data);
char	*ft_print_line(char *buffer_save);
char	*ft_get_buffer_save(char *buffer_save);
char	*ft_read(int fd, char *buffer_read);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
