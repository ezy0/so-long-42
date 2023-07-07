/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:13:46 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/07 12:34:08 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_movements(t_data *data)
{
	if (data->game->moves > 0)
	{
		ft_printf("Has realizado: %d ", data->game->moves);
		if (data->game->moves == 1)
			ft_printf("movimiento\n");
		else
			ft_printf("movimientos\n");
	}
	else
		ft_printf("Aún no te has movido\n");
}
