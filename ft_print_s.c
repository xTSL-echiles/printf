/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:52:03 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:52:05 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_print5(t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0
			&& heheboy->per == -1)
	{
		while (i < (heheboy->width - heheboy->itoa))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	else
	{
		while (i < (heheboy->width - heheboy->itoa))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	heheboy->bytes = heheboy->bytes + i;
}

char	*ft_per_cut(t_list *heheboy)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char*) * (heheboy->per));
	while (i < heheboy->per)
	{
		str[i] = heheboy->s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_all(t_list *heheboy)
{
	if (heheboy->flmin == 1)
	{
		ft_putstr_fd(heheboy->s, 1);
		ft_flag_print5(heheboy);
	}
	else
	{
		ft_flag_print5(heheboy);
		ft_putstr_fd(heheboy->s, 1);
	}
}

int		ft_null_hap(t_list *heheboy)
{
	int i;

	i = 0;
	if (heheboy->per == 0)
	{
		while (i < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		heheboy->bytes = heheboy->bytes + i;
		return (1);
	}
	return (0);
}

void	ft_print_s(t_list *heheboy)
{
	heheboy->s = va_arg(heheboy->ap, char*);
	if (ft_null_hap(heheboy))
		return ;
	if (heheboy->s == NULL)
		heheboy->s = "(null)";
	heheboy->freeme = 0;
	heheboy->itoa = ft_strlen(heheboy->s);
	if (heheboy->itoa > heheboy->per && heheboy->per != -1)
	{
		heheboy->s = ft_per_cut(heheboy);
		heheboy->itoa = ft_strlen(heheboy->s);
		heheboy->freeme = 1;
	}
	heheboy->bytes = heheboy->bytes + heheboy->itoa;
	ft_print_all(heheboy);
	if (heheboy->freeme)
		free(heheboy->s);
}
