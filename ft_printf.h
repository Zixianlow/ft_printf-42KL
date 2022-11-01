/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/10/31 18:38:27 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int	fhash;
	int	fspace;
	int	fdot;
	int	fplus;
	int	fminus;
	int	fnum;
	int	fzero;
}	t_list;

int		ft_atoi(const char *str);
t_list	*ft_initflags(t_list *f);
t_list	*ft_percent_flags(t_list *f);
int		ft_chkflags(const char s);
t_list	*ft_init_set_flags(t_list *f, const char *s);
int		ft_printf(const char *s, ...);
int		ft_print_front(t_list *f, int l, const char s);
int		ft_print_back(t_list *f, int l);
int		ft_printing(const char s, va_list p, int l, t_list *f);
int		ft_putchar(char c, int l);
int		ft_putchar_l(char c, int l);
int		ft_puthexa(unsigned int n, int fd, int type);
int		ft_gethexa(unsigned int n, int fd, int type, t_list *f);
int		ft_puthexa_l(unsigned int n, int l, int type);
int		ft_gethexa_l(unsigned int n, int l, int type, t_list *f);
int		ft_getnbr(int n, int l, t_list *f);
int		ft_putnbr(int n, int l);
int		ft_getnbr_l(int n, int l, t_list *f);
int		ft_putnbr_l(int n, int l);
int		ft_putpercent(t_list *f, int l);
int		ft_putptr(unsigned long int n, int l);
int		ft_getptr(unsigned long int n, int l, t_list *f);
int		ft_putptr_l(unsigned long int n, int l, t_list *f);
int		ft_putstr(char *s, int l, t_list *f);
int		ft_putstr_l(char *s, int l);
int		ft_putunsign(unsigned int n, int l, t_list *f);
int		ft_putunsign_l(unsigned int n, int l, t_list *f);
t_list	*ft_putchar_flags(t_list *f);
t_list	*ft_puthexa_flags(t_list *f, int l);
t_list	*ft_putnbr_flags(t_list *f, int l);
t_list	*ft_putptr_flags(t_list *f, int l);
t_list	*ft_putstr_flags(t_list *f, int l);
t_list	*ft_putunsign_flags(t_list *f, int l);

#endif