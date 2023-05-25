/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:24:44 by iobba             #+#    #+#             */
/*   Updated: 2023/01/09 10:59:52 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_long {
	int		hght;
	size_t	width;
	char	**map;
	char	**cop;
	int		nof_collect;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		nof_moves;
	void	*img_wall;
	void	*img_bg;
	void	*img_plyr;
	void	*img_door;
	void	*coins;
}	t_long;

void	get_check_map(t_long *ptr, char *av1);
char	*get_next_line(int fd);
void	error_begin(char *str);

// utils of get_next_line
int		ft_strchr_nl(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char const *s2);

// all_checks1
void	is_rectangular(t_long *ptr);
void	is_out_of5c(t_long *ptr);
void	clsdby_walls(t_long *ptr);
void	check_nof_needs(t_long *ptr, int nof_p, int nof_c, int nof_e);
void	found_needs(t_long *ptr);

// all_checks2
void	plyr_position(t_long *ptr);
int		horisontal_line(t_long *ptr, int i, int j);
int		vertical_line(t_long *ptr, int i, int j);
void	visit_map(t_long *ptr);
void	valid_path(t_long *ptr);

// utils
void	map_error(t_long *ptr, char *str);
void	freeing(char **str);
int		ft_strncmp(const char *ms1, const char *ms2, size_t n);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);

// mlx
void	mlx_map(t_long *ptr);
int		keys_func(int key, t_long *sl);
void	get_image(t_long *ptr);

// moves
void	move_to_up(t_long *sl);
void	move_to_down(t_long *sl);
void	move_to_right(t_long *sl);
void	move_to_left(t_long *sl);

// utils2
void	init_img(t_long *sl);
void	errrror(t_long *sl, char *str);

#endif
