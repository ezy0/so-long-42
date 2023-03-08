/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:25:20 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/08 19:12:13 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_map_height(t_game *game, char *map)
{
	char	*aux;
	int		fd; 
	int		i;

	fd = open(map, O_RDONLY);
	i = 1;
	aux = (char *)malloc(sizeof(char));
	if (!aux)
		return ;
	if (fd < 0)
		ft_printf("Error\nNo se ha podido abrir el archivo\n");
	else
	{
		while (i != 0)
		{
			i = read(fd, aux, 1);
			if (i < 0)
				break ;
			if (*aux == '\n' || i == 0)
				game->map_h = game->map_h + 1;
		}
	}
	free(aux);
	close(fd);
}
