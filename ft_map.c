/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:25:20 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/20 18:56:21 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_height(t_game *game, char *map)
{
	char	*aux;
	int		fd; 
	int		i;

	fd = open(map, O_RDONLY);
	i = 1;
	aux = (char *)malloc(sizeof(char));
	if (!aux)
		ft_map_error(1, game, aux);
	if (fd < 0)
		ft_map_error(0, game, aux);
	while (i != 0)
	{
		i = read(fd, aux, 1);
		if (i < 0 || (i == 0 && game->map_h == 0))
			break ;
		if (*aux == '\n' || i == 0)
			game->map_h = game->map_h + 1;
	}
	free(aux);
	close(fd);
}

void	ft_parse_map(t_game *game, char *map)
{
	int		h;
	int 	fd;
	char	*aux;
	int		i;

	h = game->map_h;
	game->map = (char **)malloc(sizeof(char) * (h + 1));
	if (!game->map)
		ft_map_error(1, game, aux);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_map_error(0, game, aux);
	while (1)	//HAY QUE HACER ESTO
	{
		i = read(fd, aux, 1);
		if (i < 0 || (i == 0 && game->map_h == 0))
			break ;
		if (*aux == '\n' || i == 0)
			game->map_h = game->map_h + 1;
	}
	close(fd);
}
