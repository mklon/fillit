/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 16:35:39 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/25 16:35:40 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_solution(int numb)
{
	int		size;
	char	**mass;

	size = 2;
	while (!(size * size >= numb * 4))
		size++;
	mass = ft_alloc_matrix(size);
	while (!ft_execution(mass, size, 0, numb))
	{
		ft_clear_mass(mass, size);
		size++;
		mass = ft_alloc_matrix(size);
	}
	ft_display_mass(mass, size);
}

char	**ft_alloc_matrix(int size)
{
	int		i;
	int		j;
	char	**mass;

	i = -1;
	j = -1;
	if ((mass = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		error(1);
	mass[size] = NULL;
	while (++i < size)
	{
		if ((mass[i] = (char*)malloc(sizeof(char) * size + 1)) == NULL)
			error(1);
		mass[i][size] = '\0';
	}
	i = -1;
	while (++i < size)
	{
		while (++j < size)
			mass[i][j] = '.';
		j = -1;
	}
	return (mass);
}

void	ft_clear_mass(char **mass, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		free(mass[i]);
	free(mass);
}

void	ft_putstr(char const *s)
{
	if (s != NULL)
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
