/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:58:00 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:25:01 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(char *img, int x, int y, t_data *data)
{
	int	w;
	int	h;

	x = x * 32;
	y = y * 32;
	data->image = mlx_xpm_file_to_image(data->mlx, img, &w, &h);
	if (!data->image)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_map_error(4, data->game, NULL, 0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, x, y);
	mlx_destroy_image(data->mlx, data->image);
}

void	ft_render(t_data *data)
{
	int		w;
	int		h;

	mlx_clear_window(data->mlx, data->win);
	ft_floor(data);
	h = 0;
	while (h < data->game->map_h)
	{
		w = 0;
		while (w < data->game->map_w)
		{
			ft_draw_walls(w, h, data->game->map[h][w], data);
			ft_draw_elements(w, h, data->game->map[h][w], data);
			w++;
		}
		h++;
	}
}

void	ft_floor(t_data *data)
{
	int	h;
	int	w;
	int	aux;

	h = -1;
	aux = 0;
	while (++h < data->game->map_h)
	{
		w = -1;
		while (++w < data->game->map_w)
		{
			if (aux % 9 == 0 || aux % 3 == 0)
				ft_put_img(FLOOR4, w, h, data);
			else if (aux % 6 == 0 || aux % 5 == 0)
				ft_put_img(FLOOR3, w, h, data);
			else if (aux % 7 == 0 || aux % 2 == 0)
				ft_put_img(FLOOR2, w, h, data);
			else
				ft_put_img(FLOOR, w, h, data);
			aux++;
		}
	}
}

void	ft_draw_walls(int w, int h, char map_char, t_data *data)
{
	if (map_char == '1' && w == 0 && h == 0)
		ft_put_img(CUL, w, h, data);
	else if (map_char == '1' && w == data->game->map_w - 1 && h == 0)
		ft_put_img(CUR, w, h, data);
	else if (map_char == '1' && w == 0 && h > 0 && h < data->game->map_h - 1)
		ft_put_img(LEFT, w, h, data);
	else if (map_char == '1' && w == data->game->map_w - 1
		&& h > 0 && h < data->game->map_h - 1)
		ft_put_img(RIGHT, w, h, data);
	else if (map_char == '1' && w >= 0 && w < data->game->map_w
		&& (h == 0 || h == data->game->map_h - 1))
		ft_put_img(WALL, w, h, data);
}

void	ft_draw_elements(int w, int h, char map_char, t_data *data)
{
	if (map_char == '1' && w > 0 && w < data->game->map_w - 1
		&& h > 0 && h < data->game->map_h - 1)
		ft_put_img(BARREL, w, h, data);
	else if (map_char == 'E' && data->game->items > 0)
		ft_put_img(DOOR_C, w, h, data);
	else if (map_char == 'E' && data->game->items == 0)
		ft_put_img(DOOR_O, w, h, data);
	else if (map_char == 'C')
		ft_put_img(KEY, w, h, data);
	else if (map_char == 'P')
	{	
		if (data->game->player_x == 0 && data->game->player_y == 0)
			ft_put_img(PLAYER, w, h, data);
		else if (w < data->game->player_x)
			ft_put_img(PLAYER_L, w, h, data);
		else
			ft_put_img(PLAYER_R, w, h, data);
		data->game->player_x = w;
		data->game->player_y = h;
	}
}
