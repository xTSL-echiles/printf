/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:44:26 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:44:28 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch6(t_list *heheboy)
{
	int		i;
	int		n;

	i = 0;
	if (heheboy->per >= heheboy->itoa)
	{
		n = heheboy->per - heheboy->itoa;
		while (i < n)
		{
			ft_putchar_fd('0', 1);
			i++;
			heheboy->bytes++;
		}
	}
}

void	ft_flag_print6(t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->width > 0)
	{
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
	}
	heheboy->bytes = heheboy->bytes + i;
}

void	ft_check_flag_again6(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_check_toch6(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		ft_flag_print6(heheboy);
		return ;
	}
	if ((heheboy->width + heheboy->freeme) > 0)
	{
		ft_flag_print6(heheboy);
		ft_putstr_fd("0x", 1);
		ft_check_toch6(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_check_toch6(heheboy);
	ft_putstr_fd(heheboy->s1, 1);
}

int		ft_null_happened6(t_list *heheboy)
{
	int j;

	j = 0;
	if (heheboy->per == 0 && heheboy->p == 0)
	{
		if (heheboy->flmin == 1)
			ft_putstr_fd("0x", 1);
		heheboy->bytes = heheboy->bytes + 2;
		while (j < heheboy->width - 2)
		{
			ft_putchar_fd(' ', 1);
			heheboy->bytes++;
			j++;
		}
		if (heheboy->flmin != 1)
			ft_putstr_fd("0x", 1);
		return (1);
	}
	return (0);
}

void	ft_print_p(t_list *heheboy)
{
	heheboy->p = va_arg(heheboy->ap, unsigned long long int);
	if (ft_null_happened6(heheboy))
		return ;
	heheboy->s1 = ft_itoa_base_p(heheboy->p, 16);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa + 2;
	heheboy->freeme = (heheboy->itoa > heheboy->per ?
		(heheboy->itoa + 2) : heheboy->per);
	heheboy->width = heheboy->width - heheboy->freeme;
	ft_check_flag_again6(heheboy);
	free(heheboy->s1);
}
