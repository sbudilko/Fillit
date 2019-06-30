/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:27:50 by sbudilko          #+#    #+#             */
/*   Updated: 2018/01/18 19:27:52 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_create_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)malloc(sizeof(map) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_number_tetro(t_tetromino *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_map_size(int i)
{
	int		res;
	int		count;

	i *= 4;
	if (i == 0)
		return (0);
	count = 0;
	while (count < i / 2)
	{
		res = count * count;
		if (res >= i)
			return (count);
		count++;
	}
	return (count);
}
