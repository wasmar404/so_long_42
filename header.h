/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:20:30 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 09:38:23 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_playerposition
{
	int		x;
	int		y;
}			t_player;

typedef struct t_countchecker
{
	int		t_counte;
	int		t_countc;
}			t_count;
typedef struct t_mapname
{
	char	*name;
}			t_name;
typedef struct ss_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*green_img;
	void	*d_img;
	void	*fox1_img;
	void	*door_img;
	char	**map;
	int		lines;
	int		linesize;
	int		j;
	int		i;
	int		countc;
	int		countoc;
	int		count_moves;
}			t_data1;

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
char		*read_line(int fd, int *position,
				int *buffer_size, char *readbuffer);
char		*add_to_line(int line_len,
				char c, char *line_to_return);
ssize_t		read_buffer_function(int fd, int *position,
				int *buffer_size, char *buffer);

int			ft_printf(const char *s, ...);
int			helper(va_list arg, char c);
int			ft_putstr(char *str);
int			ft_hexprintxpointer(long unsigned int hex);
int			t_hexprintx(unsigned int hex, char c);
int			ft_putcharr(char c);
int			hexcount(int hex);
int			percent(char c);
int			ft_putnbr(int nb);
int			ft_hexprintx(unsigned int hex, char c);

char		*fill2darray(char *mappath);
char		**array2d(char *mappath);
int			countlines(char *mappath);
int			getlinesize(char *mappath);
int			count_c(char **map, char *mappath);
int			checkc(char **map, char *mappath);
int			check_all_lines_size(char **map, char *mappath);
int			errorcheck(char **map, char *mappath);
int			errorcheck1(char **map, char *mappath);
int			errorcheck2(char *mappath);
int			checkmap(char **a, char *mappath);
int			check_valid_char(char **map, char *mappath);
int			check_valid_char_exit(char **map, int i, int j);
int			to_fill(char **map, int i, int j);
int			checkpande(char **a, char *mappath);

t_player	find_playerpos(char **map, char *mappath);
t_player	t_t_playerpos(char **map, char *mappath);
void		check_valid_path_to_coin(char **tab,
				t_player size, t_player cur, t_count *p);
void		check_path_to_coin(char **tab,
				t_player size, t_player begin, t_count *p);
void		check_valid_path_to_exit(char **tab,
				t_player size, t_player cur, t_count *p);
void		check_path_to_exit(char **tab,
				t_player size, t_player begin, t_count *p);
void		fill_player_pos_in_t_data1(t_data1 *data, char *mappath);

int			error(char **map, char *mappath);
int			allerrors(char *mappath);
void		freemem(char **map, char *mappath);
void		free_and_close(char *str, int fd);
void		free_two(char *str, char *str1);

void		on_keypress1(int keysym, t_data1 *data);
void		on_keypress2(int keysym, t_data1 *data);
void		on_keypress3(int keysym, t_data1 *data);
void		on_keypress4(int keysym, t_data1 *data);
int			on_keypress(int keysym, t_data1 *data);
void		on_keypress1_helper(t_data1 *data);
void		on_keypress2_helper(t_data1 *data);
void		on_keypress3_helper(t_data1 *data);
void		on_keypress4_helper(t_data1 *data);
int			on_destroy(t_data1 *data);

int			maprun(t_data1 *dat);
t_data1		*create_window(char *mappath);

#endif