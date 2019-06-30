/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetro_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:38:40 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/22 14:38:42 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetromino		*ft_make_tetro_lst(int fd)
{
	int				i;
	char			buff[22];
	t_tetromino		*head;

	i = 0;
	buff[21] = '\0';
	read(fd, buff, 21);
	ft_rename_tetro(buff, i);
	head = ft_new_tetro_lst(ft_clear_tetro(buff));
	while (read(fd, buff, 21) != 0)
	{
		i++;
		ft_rename_tetro(buff, i);
		ft_add_tetro_lst(head, buff);
	}
	close(fd);
	return (head);
}

t_tetromino		*ft_new_tetro_lst(char *str)
{
	t_tetromino		*new_tetro_lst;

	new_tetro_lst = (t_tetromino*)malloc(sizeof(t_tetromino));
	new_tetro_lst->figure = ft_strsplit(str, '\n');
	new_tetro_lst->x = ft_size_axis_x(new_tetro_lst->figure);
	new_tetro_lst->y = ft_size_axis_y(new_tetro_lst->figure);
	new_tetro_lst->next = NULL;
	return (new_tetro_lst);
}

void			ft_add_tetro_lst(t_tetromino *head, char *content)
{
	int flag;

	flag = 1;
	while (flag != 0)
	{
		if (head->next == NULL)
			flag = 0;
		else
			head = head->next;
	}
	head->next = ft_new_tetro_lst(ft_clear_tetro(content));
}
