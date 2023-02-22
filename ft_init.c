/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:13:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/02/22 20:13:52 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game game)
{
	game.items = 0;
	game.moves = 0;
	game.player_x = 0;
	game.player_y = 0;
	game.map_h = 0;
	game.map_w = 0;
	game.map = NULL;
}
