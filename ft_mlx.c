/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:27:05 by migmoren          #+#    #+#             */
/*   Updated: 2023/06/07 10:29:23 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_game(t_data *data)
{
	int	win_h;
	int	win_w;
	
	if (!data)
		return ;
	win_h = data->game->map_h;
	win_w = data->game->map_w;
	data->mlx = mlx_init();	//Inicializacion del mlx
	if (!data->mlx)
		ft_mlx_error(data);
	data->win = mlx_new_window(data->mlx, 
				win_w * BCKG_W, win_h * BCKG_H, "diamantes pal free");
	if (!data->win)
		ft_mlx_error(data);
	ft_render(data);
	//mlx_key_hook(data->mlx_win, ft_key, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
