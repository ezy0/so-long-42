/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:58:00 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/06 20:28:35 by migmoren         ###   ########.fr       */
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
		ft_map_error(4, data->game, NULL);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, x, y);
	mlx_destroy_image(data->mlx, data->image);
}

void	ft_render(t_data *data)
{
	int		w;
	int		h;

	mlx_clear_window(data->mlx, data->win);
	ft_floor(FLOOR, data);
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

void	ft_floor(char *bckg, t_data *data)
{
	int	h;
	int w;

	h = 0;
	while (h < data->game->map_h)
	{
		w = 0;
		while (w < data->game->map_w)
		{
			ft_put_img(bckg, w, h, data);
			w++;
		}
		h++;
	}
}

void	ft_draw_walls(int w, int h, char map_char, t_data *data)
{
	if (map_char == '1' && w == 0 && h == 0)
		ft_put_img(CUL, w, h, data);
	else if (map_char == '1' && w == data->game->map_w - 1 && h == 0)
		ft_put_img(CUR, w, h, data);
	else if (map_char == '1' && w == 0 && h > 0 && h < data->game->map_h-1)
		ft_put_img(LEFT, w, h, data);
	else if (map_char == '1' && w == data->game->map_w - 1 
			&& h > 0 && h < data->game->map_h-1)
		ft_put_img(RIGHT, w, h, data);
	else if (map_char == '1' && w >= 0 && w < data->game->map_w 
		&& (h == 0 || h == data->game->map_h - 1))
		ft_put_img(WALL, w, h, data);
}

void	ft_draw_elements(int w, int h, char map_char, t_data *data)
{
	if (map_char == '1' && w > 0 && w < data->game->map_w-1
		&& h > 0 && h < data->game->map_h - 1)
		ft_put_img(BARREL, w, h, data);
	else if (map_char == 'E')
		ft_put_img(DOOR_C, w, h, data);
}
