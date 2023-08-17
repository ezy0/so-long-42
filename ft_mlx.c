/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:27:05 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:56:05 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement(int x, int y, t_data *data)
{
	if (data->game->map[y][x] == '1')
		return ;
	if (data->game->map[y][x] == 'E' && data->game->items != 0)
		return ;
	else if (data->game->map[y][x] == 'E' && data->game->items == 0)
	{
		ft_printf("**** ¡HAS ESCAPADO! ****\n");
		ft_exit(data);
	}
	if (data->game->map[y][x] == 'C')
	{
		data->game->map[y][x] = '0';
		data->game->items--;
	}
	ft_render(data);
	ft_draw_elements(x, y, 'P', data);
	data->game->player_x = x;
	data->game->player_y = y;
	data->game->moves++;
	ft_print_movements(data);
}

int	ft_keys(int key, t_data *data)
{
	data->game->map[data->game->player_y][data->game->player_x] = '0';
	if (key == ESC)
	{
		ft_printf("Has cerrado el juego :( \n");
		ft_exit(data);
	}
	else if (key == W)
		ft_movement(data->game->player_x, data->game->player_y - 1, data);
	else if (key == A)
		ft_movement(data->game->player_x - 1, data->game->player_y, data);
	else if (key == S)
		ft_movement(data->game->player_x, data->game->player_y + 1, data);
	else if (key == D)
		ft_movement(data->game->player_x + 1, data->game->player_y, data);
	return (0);
}

void	ft_mlx_game(t_data *data)
{
	int	win_h;
	int	win_w;

	if (!data)
		return ;
	win_h = data->game->map_h;
	win_w = data->game->map_w;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_mlx_error(data);
	data->win = mlx_new_window(data->mlx,
			win_w * BCKG_W, win_h * BCKG_H, "<><><> SO LONG <><><>");
	if (!data->win)
		ft_mlx_error(data);
	ft_render(data);
	if (!ft_valid_path(data->game) || !ft_valid_keys(data->game))
	{
		ft_printf("Error\nNo se encuentra ningún camino válido\n");
		ft_exit(data);
	}
	mlx_key_hook(data->win, ft_keys, data);
	ft_print_movements(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
