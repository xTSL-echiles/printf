/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:42:06 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:42:08 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch(t_list *heheboy)
{
	int		i;
	int		n;

	i = 0;
	if (heheboy->per >= heheboy->itoa)
	{
		n = heheboy->per - heheboy->itoa + (heheboy->d < 0 ? 1 : 0);
		while (i < n)
		{
			ft_putchar_fd('0', 1);
			i++;
			heheboy->bytes++;
		}
	}
}

void	ft_flag_print(t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0
			&& heheboy->per == -1)
	{
		while (i < heheboy->width)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	else
	{
		while (i < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	heheboy->bytes = heheboy->bytes + i;
}

void	ft_check_flag_again(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_check_toch(heheboy);
		ft_putnbr_fd(heheboy->d, 1);
		ft_flag_print(heheboy);
		return ;
	}
	if ((heheboy->width + heheboy->freeme) > heheboy->per || heheboy->zero == 1)
	{
		if (heheboy->zero == 1 && heheboy->per == -1 && heheboy->flmin == 0)
			heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_flag_print(heheboy);
		if (heheboy->zero != 1 || heheboy->per != -1 || heheboy->flmin != 0)
			heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_check_toch(heheboy);
		ft_putnbr_fd(heheboy->d, 1);
		return ;
	}
	heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
	ft_flag_print(heheboy);
	ft_check_toch(heheboy);
	ft_putnbr_fd(heheboy->d, 1);
}

int		ft_null_happened(t_list *heheboy)
{
	int j;

	j = 0;
	if (heheboy->per == 0 && heheboy->d == 0)
	{
		while (j < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			heheboy->bytes++;
			j++;
		}
		return (1);
	}
	return (0);
}

void	ft_print_di(t_list *heheboy)
{
	heheboy->d = va_arg(heheboy->ap, int);
	if (ft_null_happened(heheboy))
		return ;
	heheboy->s1 = ft_itoa(heheboy->d);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa;
	heheboy->freeme = (heheboy->per < heheboy->itoa ?
		heheboy->itoa : heheboy->per);
	if (heheboy->per >= heheboy->itoa && heheboy->d < 0)
		heheboy->freeme++;
	heheboy->width = heheboy->width - heheboy->freeme;
	ft_check_flag_again(heheboy);
	free(heheboy->s1);
}
