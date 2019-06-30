/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:24:50 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/19 17:26:13 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_tetromino(t_tetromino *lst)
{
	int		map_size;
	char	**map;

	if (ft_number_tetro(lst) > 26)
	{
		ft_putendl("error");
		return ;
	}
	map_size = ft_map_size(ft_number_tetro(lst));
	map = ft_create_map(map_size);
	while (ft_solve(map, lst, map_size) == 0)
		map = ft_create_map(++map_size);
}

int		main(int argc, char **argv)
{
	t_tetromino	*tetro_lst;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetraminos_file");
		return (0);
	}
	if ((ft_primary_validation(open(argv[1], O_RDONLY))) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	tetro_lst = ft_make_tetro_lst(open(argv[1], O_RDONLY));
	ft_tetromino(tetro_lst);
	return (0);
}
