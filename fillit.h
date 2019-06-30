/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:25:06 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/09 17:46:20 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_tetro
{
	int				x;
	int				y;
	char			**figure;
	struct s_tetro	*next;
}					t_tetromino;

int					ft_primary_validation(int fd);
int					ft_valid_char(char *str);
int					ft_valid_quantity_hash(char *str);
int					ft_valid_tetromino(char *str);
t_tetromino			*ft_make_tetro_lst(int fd);
t_tetromino			*ft_new_tetro_lst(char *str);
void				ft_add_tetro_lst(t_tetromino *head, char *content);
char				*ft_clear_tetro(char *str);
int					ft_solve(char **map, t_tetromino *lst, int map_size);
void				ft_rename_tetro(char *str, int count);
int					ft_map_size(int i);
int					ft_number_tetro(t_tetromino *lst);
char				**ft_create_map(int size);
int					ft_size_axis_x(char **figure);
int					ft_size_axis_y(char **figure);
char				**ft_put_tetro(char **map, t_tetromino *lst, int x, int y);
int					ft_verif(char **map, t_tetromino *lst);
int					ft_verif_2(char **map, t_tetromino *lst, int x, int y);
void				ft_clear_map(char **map);
char				**ft_copy_map(char **map, int map_size);
char				**ft_copy_map(char **map, int map_size);
void				ft_print_map(char **map);

#endif
