/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:33:30 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/31 19:56:18 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_chklength_pid(const char s, va_list o, t_list *f)
{
	int	l;

	l = 0;
	if (s == 'p')
	{
		l = ft_putptr_l(va_arg(o, unsigned long int), l, f);
		l = l + 2;
		f = ft_putptr_flags(f, l);
	}
	else if (s == 'd' || s == 'i')
	{
		l = ft_getnbr_l(va_arg(o, int), l, f);
		f = ft_putnbr_flags(f, l);
	}
	return (f);
}

t_list	*ft_chklength_uxpercent(const char s, va_list o, t_list *f)
{
	int	l;

	l = 0;
	if (s == 'u')
	{
		l = ft_putunsign_l(va_arg(o, unsigned int), l, f);
		f = ft_putunsign_flags(f, l);
	}
	else if (s == 'x')
	{
		l = ft_gethexa_l(va_arg(o, unsigned int), l, 1, f);
		f = ft_puthexa_flags(f, l);
	}
	else if (s == 'X')
	{
		l = ft_gethexa_l(va_arg(o, unsigned int), l, 2, f);
		f = ft_puthexa_flags(f, l);
	}
	else if (s == '%')
	{
		l = ft_putchar_l('%', l);
		f = ft_percent_flags(f);
	}
	return (f);
}

t_list	*ft_chklength(const char s, va_list o, t_list *f)
{
	int	l;

	l = 0;
	if (s == 'c')
	{
		l = ft_putchar_l(va_arg(o, int), l);
		f = ft_putchar_flags(f);
	}
	else if (s == 's')
	{
		l = ft_putstr_l(va_arg(o, char *), l);
		f = ft_putstr_flags(f, l);
	}
	f = ft_chklength_pid(s, o, f);
	f = ft_chklength_uxpercent(s, o, f);
	return (f);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			l;
	va_list		o;
	va_list		p;
	t_list		*f;

	va_start(p, s);
	i = -1;
	l = 0;
	va_copy(o, p);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			f = ft_init_set_flags(f, (s + 1 + i++));
			while (ft_chkflags(s[i]) && s[i + 1])
				i++;
			f = ft_chklength(s[i], o, f);
			l = ft_printing(s[i], p, l, f);
		}
		else
			l = ft_putchar(s[i], l);
	}
	va_end(p);
	return (l);
}
