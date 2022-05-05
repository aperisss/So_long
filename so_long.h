/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:40:49 by aperis            #+#    #+#             */
/*   Updated: 2022/02/12 13:35:07 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <mlx.h>
# include <X11/keysym.h>

typedef struct s_data
{
	int		i;
	int		j;
	char	*src;

	int		len;
	int		p_count;
	int		e_count;
	int		c_count;
	int		count;
	char	*str;

	int		countmove;
	void	*hero;
	void	*coll;
	void	*wall;
	void	*exit;
	void	*floor;

	void	*mlx_ptr;
	void	*mlx_win;
}	t_data;

int				ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_get_line(char *save);
char			*ft_save(char *save);
char			*ft_read_and_save(int fd, char *save);

void			ft_free_all(t_data *data);
void			ft_error(char *tmp, char *str);
void			ft_malloc_error(char *str);

t_data			ft_check(char *str, int count, char *tmp);
t_data			ft_check2(char *str, int count, char *tmp);
t_data			ft_check3(char *str, int count, char *tmp);
t_data			ft_check4(char *str, int count, t_data data, char *tmp);
t_data			ft_parsing(int fd, t_data data);

int				ft_hook(int keysym, t_data *data);
int				ft_esc(t_data *data);
int				ft_mouse_close(t_data *data);
t_data			ft_w(t_data data);
t_data			ft_a(t_data data);
t_data			ft_s(t_data data);
t_data			ft_d(t_data data);

t_data			ft_new_window(t_data data);
t_data			ft_load(t_data data, int s);
void			ft_aff_map(t_data data);
void			ft_aff_wall(t_data data);
void			ft_aff_floor(t_data data);
void			ft_aff_hero(t_data data);
void			ft_aff_coll(t_data data);
void			ft_aff_exit(t_data data);

void			ft_check_arg(int ac, char **av, int fd);

#endif
