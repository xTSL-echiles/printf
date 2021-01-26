/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:00:43 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:00:45 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch1(t_list *heheboy)
{
	int		i;
	int		n;

	i = 0;
	if (heheboy->per > heheboy->itoa)
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

void	ft_flag_print10(t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0
			&& heheboy->per == -1)
	{
		while (i < heheboy->width - heheboy->freeme)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	else
	{
		while (i < heheboy->width - heheboy->freeme)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	heheboy->bytes = heheboy->bytes + i;
}

void	ft_check_flag_again1(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		ft_check_toch1(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		ft_flag_print10(heheboy);
		return ;
	}
	if ((heheboy->width > heheboy->per && heheboy->zero == 0)
	|| heheboy->zero == 1)
	{
		ft_flag_print10(heheboy);
		ft_check_toch1(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		return ;
	}
	ft_flag_print10(heheboy);
	ft_check_toch1(heheboy);
	ft_putstr_fd(heheboy->s1, 1);
}

int		ft_null_happened1(t_list *heheboy)
{
	int	j;

	j = 0;
	if (heheboy->per == 0 && heheboy->u == 0)
	{
		while (j < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			j++;
			heheboy->bytes++;
		}
		return (1);
	}
	return (0);
}

void	ft_print_x(t_list *heheboy)
{
	heheboy->u = va_arg(heheboy->ap, unsigned int);
	if (ft_null_happened1(heheboy))
		return ;
	heheboy->s1 = ft_itoa_base_x(heheboy->u, 16);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa;
	ft_tolower1(heheboy->s1);
	heheboy->freeme = ((heheboy->per < heheboy->itoa) ?
		heheboy->itoa : heheboy->per);
	ft_check_flag_again1(heheboy);
	free(heheboy->s1);
}
