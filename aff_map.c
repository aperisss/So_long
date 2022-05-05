/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:29:57 by aperis            #+#    #+#             */
/*   Updated: 2022/01/27 14:25:09 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_new_window(t_data data)
{
	if (data.len > 39 || data.count > 21)
	{
		printf("Error, valid map but to big for your screen.\n");
		exit(0);
	}
	data.countmove = 0;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.len * 64,
			data.count * 64, "so_long");
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		exit(1);
	}
	return (data);
}

t_data	ft_load(t_data data, int s)
{
	data.hero = mlx_xpm_file_to_image(data.mlx_ptr, "./xpm/hero.xpm", &s, &s);
	data.wall = mlx_xpm_file_to_image(data.mlx_ptr, "./xpm/wall.xpm", &s, &s);
	data.coll = mlx_xpm_file_to_image(data.mlx_ptr, "./xpm/coll.xpm", &s, &s);
	data.exit = mlx_xpm_file_to_image(data.mlx_ptr, "./xpm/exit.xpm", &s, &s);
	data.floor = mlx_xpm_file_to_image(data.mlx_ptr, "./xpm/floor.xpm", &s, &s);
	return (data);
}

void	ft_aff_map(t_data data)
{
	ft_aff_wall(data);
	ft_aff_floor(data);
	ft_aff_hero(data);
	ft_aff_coll(data);
	ft_aff_exit(data);
}

int	ft_hook(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_esc(data);
	if (keysym == 119)
		*data = ft_w(*data);
	if (keysym == 97)
		*data = ft_a(*data);
	if (keysym == 115)
		*data = ft_s(*data);
	if (keysym == 100)
		*data = ft_d(*data);
	ft_aff_map(*data);
	return (0);
}
