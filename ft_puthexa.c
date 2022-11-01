/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:42:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/29 15:16:25 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, int l, int type)
{
	char	*h1;
	char	*h2;

	h1 = "0123456789abcdef";
	h2 = "0123456789ABCDEF";
	if (n < 0)
		n = 4294967295 + n;
	if (n >= 0)
	{
		if (n / 16 > 0)
			l = ft_puthexa(n / 16, l, type);
		if (type == 1)
			l = ft_putchar(h1[n % 16], l);
		else if (type == 2)
			l = ft_putchar(h2[n % 16], l);
	}
	return (l);
}

int	ft_gethexa(unsigned int n, int l, int type, t_list *f)
{
	while (f->fzero > 0)
	{
		write(1, "0", 1);
		l++;
		f->fzero--;
	}
	if (f->fdot == 1 && n == 0)
		return (l);
	while (f->fdot > 2)
	{
		write(1, "0", 1);
		l++;
		f->fdot--;
	}
	l = ft_puthexa(n, l, type);
	return (l);
}
