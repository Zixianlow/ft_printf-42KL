/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:08:22 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/31 19:20:06 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_zero(int l, t_list *f)
{
	while (f->fzero > 0)
	{
		write(1, "0", 1);
		l++;
		f->fzero--;
	}
	return (l);
}

int	ft_putstr(char *s, int l, t_list *f)
{
	int	i;

	i = 0;
	if (!s)
	{
		l = ft_putstr("(null)", l, f);
		return (l);
	}
	l = ft_putstr_zero(l, f);
	if (f->fdot > 0)
	{
		while (s[i])
		{
			if (f->fdot == 1)
				break ;
			l = ft_putchar(s[i++], l);
			f->fdot--;
		}
	}
	else
		while (s[i])
			l = ft_putchar(s[i++], l);
	return (l);
}
