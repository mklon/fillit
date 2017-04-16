/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:13:16 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/19 14:13:17 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

struct		s_base
{
	int		x[3];
	int		y[3];
	char	letter;
}			;

int			main(int argc, char **argv);
void		ft_map_check(char *buff, int i);
void		ft_map_check2(char *buff, int i);
void		error(int i);
void		ft_write_map(char *buff, int sct, int i);
void		ft_solution(int	numb);
char		**ft_alloc_matrix(int size);
void		ft_clear_mass(char **mass, int size);
int			ft_execution(char **mass, int size, int sct, int numb);
int			ft_insert(int sct, char **mass, int i, int j);
int			ft_remove(int sct, char **mass, int i, int j);
void		ft_display_mass(char **mass, int size);
void		ft_putstr(char const *s);
void		ft_putchar(char c);

#endif
