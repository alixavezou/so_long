/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:17:55 by aavezou           #+#    #+#             */
/*   Updated: 2022/07/20 19:28:46 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>

typedef struct	env	env;
struct env
{
	void		*mlx;
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

	char		**map;
	char		*file_name;
};

size_t	ft_strlen(char *str);
void 	init_map(env *so_long);
int		ft_recup_map_size(char *file_name);
int 	key_hook(int keycode, void *param);
int		mouse_hook(int keycode, void *param);
int		ft_checkendofline(char *buffer_save);

void 	ft_print_walls(env env);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	ft_print_map(env *file_name);
char	*ft_print_line(char *buffer_save);
char	*ft_get_buffer_save(char *buffer_save);
char	*ft_read(int fd, char *buffer_read);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
