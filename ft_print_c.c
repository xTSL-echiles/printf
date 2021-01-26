/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:25:24 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:25:25 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_print4(t_list *heheboy)
{
	int	i;

	i = 0;
	while (i < (heheboy->width - 1))
	{
		ft_putchar_fd(' ', 1);
		i++;
		heheboy->bytes++;
	}
}

void	ft_check_flag_again4(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		ft_putchar_fd(heheboy->d, 1);
		ft_flag_print4(heheboy);
		return ;
	}
	ft_flag_print4(heheboy);
	ft_putchar_fd(heheboy->d, 1);
}

void	ft_print_c(t_list *heheboy)
{
	heheboy->d = va_arg(heheboy->ap, int);
	heheboy->bytes++;
	ft_check_flag_again4(heheboy);
}
