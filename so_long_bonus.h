/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:24:44 by iobba             #+#    #+#             */
/*   Updated: 2023/01/09 11:50:02 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*wn;
	int		x;
	int		y;
	int		n_mvs;
	int		iterater;
	int		iterater2;
	char	*str;
	void	*img_wall;
	void	*img_bg;
	void	*img_p;
	void	*img_n;
	void	*img_c;
	void	*img_o;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
}	t_long;

void	get_check_map(t_long *ptr, char *av1);
char	*get_next_line(int fd);
void	errrror(t_long *sl, char *str);
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
void	player_position(t_long *ptr);
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
void	get_image(t_long *ptr);
int		ft_close(t_long *sl);
void	init_img(t_long *sl);

// moves
void	move_to_up(t_long *sl);
void	move_to_down(t_long *sl);
void	move_to_right(t_long *sl);
void	move_to_left(t_long *sl);
int		keys_func(int key, t_long *sl);
void	put_nofmvs(t_long *sl);
char	*ft_itoa(int nb);

// generate_coins
void	*g(t_long *sl);
int		l_func(t_long *sl);

// enemy
void	enemy_move(t_long *sl);
int		enemy_f(t_long *sl);
void	death(t_long *sl);
void	enemy_way(t_long *sl, int *m, int *n);

#endif
