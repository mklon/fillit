/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:43:51 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/26 14:43:52 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

extern struct s_base	bs[26];

int		ft_execution(char **mass, int size, int sct, int numb)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (sct == numb)
		return (1);
	while (++i < size)
	{
		while (++j < size)
		{
			if (ft_insert(sct, mass, i, j))
			{
				if (ft_execution(mass, size, sct + 1, numb))
					return (1);
				else
					ft_remove(sct, mass, i, j);
			}
		}
		j = -1;
	}
	return (0);
}

int		ft_insert(int sct, char **mass, int i, int j)
{
	int		size;
	int		f;
	char	c;

	f = -1;
	size = 0;
	while (mass[0][size] != '\0')
		size++;
	while (++f < 3)
		if (i + bs[sct].x[f] < 0 || i + bs[sct].x[f] > (size - 1)
			|| j + bs[sct].y[f] < 0 || j + bs[sct].y[f] > (size - 1))
			return (0);
	if (mass[i][j] != '.' || mass[i + bs[sct].x[0]][j + bs[sct].y[0]] != '.' ||
		mass[i + bs[sct].x[1]][j + bs[sct].y[1]] != '.' ||
		mass[i + bs[sct].x[2]][j + bs[sct].y[2]] != '.')
		return (0);
	else
		c = bs[sct].letter;
	f = -1;
	mass[i][j] = c;
	while (++f < 3)
		mass[i + bs[sct].x[f]][j + bs[sct].y[f]] = c;
	return (1);
}

int		ft_remove(int sct, char **mass, int i, int j)
{
	int		f;
	char	c;

	f = -1;
	c = '.';
	mass[i][j] = c;
	while (++f < 3)
		mass[i + bs[sct].x[f]][j + bs[sct].y[f]] = c;
	return (1);
}

void	ft_display_mass(char **mass, int size)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			write(1, &mass[i][j], 1);
		write(1, "\n", 1);
		j = -1;
	}
}
