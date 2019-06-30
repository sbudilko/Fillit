/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_tetro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:47 by sbudilko          #+#    #+#             */
/*   Updated: 2018/01/27 18:56:48 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void			ft_rename_tetro(char *str, int count)
{
	while (*str != '\0')
	{
		if (*str == '#')
			*str = 'A' + count;
		str++;
	}
}

char			*ft_clear_tetro(char *str)
{
	int		i;

	i = -5;
	while ((i += 5) < 20)
		if (str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '.' &&
			str[i + 3] == '.')
		{
			str[i] = '\n';
			str[i + 1] = '\n';
			str[i + 2] = '\n';
			str[i + 3] = '\n';
		}
	i = -1;
	while (++i < 5)
		if ((str[i] == '.' || str[i] == '\n') &&
			(str[i + 5] == '.' || str[i + 5] == '\n') &&
			(str[i + 10] == '.' || str[i + 10] == '\n') &&
			(str[i + 15] == '.' || str[i + 15] == '\n'))
		{
			str[i] = '\n';
			str[i + 5] = '\n';
			str[i + 10] = '\n';
			str[i + 15] = '\n';
		}
	return (str);
}

int				ft_size_axis_y(char **figure)
{
	return (ft_strlen(figure[0]));
}

int				ft_size_axis_x(char **figure)
{
	int i;

	i = 0;
	while (figure[i] != NULL)
		i++;
	return (i);
}
