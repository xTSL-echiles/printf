/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:04:52 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:04:54 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	t_list	*heheboy;
	int		n;

	heheboy = (t_list*)malloc(sizeof(t_list));
	heheboy->fmtt = fmt;
	heheboy->count = 0;
	heheboy->bytes = 0;
	va_start(heheboy->ap, fmt);
	ft_print_other(heheboy);
	va_end(heheboy->ap);
	n = heheboy->bytes;
	free(heheboy);
	return (n);
}
