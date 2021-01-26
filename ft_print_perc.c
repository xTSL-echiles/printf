/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:46:49 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:46:50 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_print7(t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0)
	{
		while (i < (heheboy->width - 1))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	else
	{
		while (i < (heheboy->width - 1))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	heheboy->bytes = heheboy->bytes + i;
}

void	ft_check_flag_again7(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		ft_putchar_fd('%', 1);
		ft_flag_print7(heheboy);
		return ;
	}
	ft_flag_print7(heheboy);
	ft_putchar_fd('%', 1);
}

void	ft_print_perc(t_list *heheboy)
{
	heheboy->bytes++;
	ft_check_flag_again7(heheboy);
}
