/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_set_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:12:40 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/31 18:49:24 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_setflags_dot(t_list *f, const char *s)
{
	int	i;
	int	n;

	i = 0;
	while (ft_chkflags(s[i]) == 1)
	{
		if (s[i] == '.')
		{
			i++;
			if (s[i] >= '0' && s[i] <= '9')
			{
				n = ft_atoi(s + i);
				f->fdot = n;
			}
			f->fdot++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		i++;
	}
	return (f);
}

t_list	*ft_setflags_zero_content(t_list *f, const char *s, int i, int n)
{
	n = ft_atoi(s + i);
	f->fzero = n;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
	{
		f->fnum = f->fzero;
		f->fzero = 0;
	}
	return (f);
}

t_list	*ft_setflags_num_zero(t_list *f, const char *s)
{
	int	i;
	int	n;

	i = 0;
	while (ft_chkflags(s[i]) == 1)
	{
		if (s[i] == '0')
		{
			f = ft_setflags_zero_content(f, s, i, n);
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		if (s[i] >= '1' && s[i] <= '9')
		{
			n = ft_atoi(s + i);
			f->fnum = n;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		if (s[i] == '.')
			break ;
		i++;
	}
	return (f);
}

t_list	*ft_setflags(t_list *f, const char *s)
{
	int	i;

	i = 0;
	while (ft_chkflags(s[i]) == 1)
	{
		if (s[i] == ' ')
			f->fspace = 1;
		else if (s[i] == '-')
			f->fminus = 1;
		else if (s[i] == '+')
			f->fplus = 1;
		else if (s[i] == '#')
			f->fhash = 1;
		i++;
	}
	f = ft_setflags_num_zero(f, s);
	f = ft_setflags_dot(f, s);
	return (f);
}

t_list	*ft_init_set_flags(t_list *f, const char *s)
{
	f = ft_initflags(f);
	f = ft_setflags(f, s);
	return (f);
}
