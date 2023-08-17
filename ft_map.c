/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:25:20 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:24:10 by migmoren         ###   ########.fr       */
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
		ft_map_error(1, game, aux, 0);
	if (fd < 0)
		ft_map_error(0, game, aux, 0);
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
	int		i;
	int		fd;
	char	*aux;

	i = -1;
	game->map = (char **)malloc(sizeof(char *) * (game->map_h + 1));
	if (!game->map)
		ft_map_error(1, game, NULL, 0);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_map_error(0, game, NULL, 1);
	while (1)
	{
		aux = NULL;
		aux = get_next_line(fd);
		if (!aux)
			break ;
		game->map[++i] = ft_strdup(aux);
		if (!game->map[i])
			ft_map_error(1, game, aux, 0);
		free(aux);
	}
	close(fd);
	game->map[++i] = 0;
}
