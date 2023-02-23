/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:14 by migmoren          #+#    #+#             */
/*   Updated: 2022/11/01 19:27:38 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char const *str)
{
	if (!str)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write (1, str, ft_strlen(str)));
}
