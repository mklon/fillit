/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:09:10 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/19 14:09:11 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct s_base	bs[26];

void	error(int i)
{
	if (i == 0)
		ft_putstr("usage: ./fillit source_file\n");
	if (i == 1)
		ft_putstr("error\n");
	exit(1);
}

void	ft_write_map(char *buff, int sct, int i)
{
	int			f;
	int			num;
	int			zero;

	f = 0;
	num = 0;
	while (++i < 20)
	{
		if (buff[i] != '#')
			continue;
		if (buff[i] == '#' && f == 0)
		{
			f = 1;
			zero = i;
		}
		else
		{
			bs[sct].y[f - 1] = i % 5 - zero % 5;
			bs[sct].x[f - 1] = i / 5 - zero / 5;
			bs[sct].letter = 'A' + sct;
			f++;
		}
	}
}

void	ft_map_check2(char *buff, int k)
{
	int		i;
	int		f;
	int		t;

	i = -1;
	f = 0;
	t = 0;
	while (++i < 20)
	{
		if (buff[i] != '#')
			continue;
		f++;
		if (buff[i + 1] == '#')
			t++;
		if (buff[i + 5] == '#')
			t++;
		if (buff[i - 1] == '#')
			t++;
		if (buff[i - 5] == '#')
			t++;
	}
	if (t != 6 && t != 8)
		error(1);
	ft_write_map(&buff[0], k, -1);
}

void	ft_map_check(char *buf, int k)
{
	int		i;
	int		dot;
	int		sharp;

	i = -1;
	dot = 0;
	sharp = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		error(1);
	while (++i < 20)
	{
		if (buf[i] == '.')
			dot++;
		else if (buf[i] == '#')
			sharp++;
		else if (buf[i] == '\n')
			;
		else
			error(1);
	}
	if (dot != 12 || sharp != 4)
		error(1);
	ft_map_check2(&buf[0], k);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	buff[21];

	i = 0;
	j = -1;
	if (argc != 2)
		error(0);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff[0], 20))
	{
		ft_map_check(&buff[0], i);
		while (++j < 21)
			buff[j] = '\0';
		if (read(fd, &buff[0], 1) != 0 && buff[0] != '\n')
			error(1);
		i++;
		j = -1;
	}
	if (i == 0 || i > 26 || buff[0] != '\0')
		error(1);
	ft_solution(i);
	close(fd);
	return (0);
}
