/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:04:19 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/20 15:04:22 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_primary_validation(int fd)
{
	char	buff[22];
	char	last;
	int		flag;

	flag = 1;
	last = '\n';
	ft_bzero(buff, 22);
	while (read(fd, buff, 21))
	{
		if (ft_valid_char(buff) == 0 || ft_valid_quantity_hash(buff) == 0 ||
			ft_valid_tetromino(buff) == 0)
			flag = 0;
		if (flag == 0)
		{
			close(fd);
			return (0);
		}
		last = buff[20];
		ft_bzero(buff, 22);
	}
	close(fd);
	if (last == '\n')
		return (0);
	return (1);
}

int		ft_valid_char(char *str)
{
	size_t	len;
	int		i;

	i = -1;
	if ((len = ft_strlen(str)) == 21 || len == 20)
	{
		while (++i < 20)
		{
			if ((i + 1) % 5 == 0 && *str != '\n')
				return (0);
			if ((i + 1) % 5 != 0 && *str != '.' && *str != '#')
				return (0);
			str++;
		}
		if (*str != '\n' && *str != '\0')
			return (0);
		return (1);
	}
	else
		return (0);
}

int		ft_valid_quantity_hash(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (i++ < 20)
		if (*str++ == '#')
			count++;
	if (count != 4)
		return (0);
	return (1);
}

int		ft_valid_tetromino(char *str)
{
	int flag;
	int i;

	flag = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				flag++;
			if (str[i + 5] == '#')
				flag++;
		}
		i++;
	}
	if (flag == 3 || flag == 4)
		return (1);
	return (0);
}
