/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:55 by aavezou           #+#    #+#             */
/*   Updated: 2022/07/24 19:42:38 by alixavezou       ###   ########.fr       */
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
	void		*image;
	void		*wall;
	void		*collectible;
	void		*player;
	void		*exit;
	void		*empty;

	int			x;
	int			y;
	int			map_size;
	int			total_nb_line;
	int			total_nb_col;

	char		**map;
	char		*file_name;
};

//KEYCODE
# define ESC 53
# define GO_UP 119
# define GO_DOWN 115
# define GO_LEFT 97
# define GO_RIGHT 100

size_t	ft_strlen(char *str);

void 	init_map(t_data *so_long);
void	ft_recup_map_size(t_data *data);
void	ft_errors_map(t_data *data);

int		key_hook(int keycode, t_data *data);
int		handle_no_event(void *data);
int		ft_checkendofline(char *buffer_save);
int		ft_check_walls(t_data *data);

void 	ft_print_walls(t_data env);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_print_map(t_data *data);
char	*ft_print_line(char *buffer_save);
char	*ft_get_buffer_save(char *buffer_save);
char	*ft_read(int fd, char *buffer_read);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
