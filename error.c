/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:02 by aperis            #+#    #+#             */
/*   Updated: 2022/02/12 13:35:01 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *tmp, char *str)
{
	free(tmp);
	free(str);
	printf("Invalid map");
	exit(0);
}

void	ft_malloc_error(char *str)
{
	if (!str)
		exit(0);
}

void	ft_free_all(t_data *data)
{
	free(data->str);
	mlx_destroy_image(data->mlx_ptr, data->hero);
	mlx_destroy_image(data->mlx_ptr, data->coll);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	ft_mouse_close(t_data *data)
{
	ft_free_all(data);
	exit(1);
	return (0);
}

int	ft_esc(t_data *data)
{
	ft_free_all(data);
	exit(1);
	return (0);
}
