/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:19 by aperis            #+#    #+#             */
/*   Updated: 2022/01/27 14:12:39 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_aff_wall(t_data data)
{
	data.i = 0;
	data.j = 0;
	data.len = 0;
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
		{
			data.i++;
			data.len++;
			data.j = 0;
		}
		if (data.str[data.i] == '1')
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
				data.wall, data.j * 64, data.len * 64);
		data.i++;
		data.j++;
	}
}

void	ft_aff_floor(t_data data)
{
	data.i = 0;
	data.j = 0;
	data.len = 0;
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
		{
			data.i++;
			data.len++;
			data.j = 0;
		}
		if (data.str[data.i] == '0')
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
				data.floor, data.j * 64, data.len * 64);
		data.i++;
		data.j++;
	}
}

void	ft_aff_hero(t_data data)
{
	data.i = 0;
	data.j = 0;
	data.len = 0;
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
		{
			data.i++;
			data.len++;
			data.j = 0;
		}
		if (data.str[data.i] == 'P')
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
				data.hero, data.j * 64, data.len * 64);
		data.i++;
		data.j++;
	}
}

void	ft_aff_coll(t_data data)
{
	data.i = 0;
	data.j = 0;
	data.len = 0;
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
		{
			data.i++;
			data.len++;
			data.j = 0;
		}
		if (data.str[data.i] == 'C')
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.coll,
				data.j * 64, data.len * 64);
		data.i++;
		data.j++;
	}
}

void	ft_aff_exit(t_data data)
{
	data.i = 0;
	data.j = 0;
	data.len = 0;
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
		{
			data.i++;
			data.len++;
			data.j = 0;
		}
		if (data.str[data.i] == 'E')
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
				data.exit, data.j * 64, data.len * 64);
		data.i++;
		data.j++;
	}
}
