/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:31:22 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/31 18:26:45 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_putptr_flags(t_list *f, int l)
{
	f->fplus = 0;
	f->fhash = 0;
	f->fspace = 0;
	if (f->fdot == 1)
		f->fdot = 1;
	else if (f->fdot > l)
		f->fdot = f->fdot - l + 3;
	else
		f->fdot = 0;
	if (f->fdot > 0)
		l = l + f->fdot - 1;
	else
		l = l + f->fdot;
	if (f->fnum >= l)
	{
		f->fnum = f->fnum - l + 1;
		if (f->fdot == 0 || f->fdot == 1)
			f->fnum--;
	}
	else
		f->fnum = 0;
	f->fzero = 0;
	return (f);
}

int	ft_putptr_l(unsigned long int n, int l, t_list *f)
{
	char	*h;

	if (f->fdot == 1 && n == 0)
		return (l);
	h = "0123456789abcdef";
	if (n >= 0)
	{
		if (n / 16 > 0)
			l = ft_putptr_l(n / 16, l, f);
		l = ft_putchar_l(h[n % 16], l);
	}
	return (l);
}
