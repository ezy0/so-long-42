/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:00:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/20 18:50:45 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(int error, t_game *game, char *aux)
{
	if (error == 0)
		ft_printf("Error\nNo se ha podido abrir el archivo\n");
	if (error == 1)
		ft_printf("Error\nFallo de memoria\n");

	if (aux)
		free(aux);
	free(game);
	exit (1);
}