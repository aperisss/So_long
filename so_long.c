/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:17 by aperis            #+#    #+#             */
/*   Updated: 2022/01/27 14:11:54 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arg(int ac, char **av, int fd)
{
	int		i;

	if (fd == -1)
	{
		printf("Error, the map doesn't exist. Please enter a valid file\n");
		exit (0);
	}
	if (ac != 2)
	{
		printf("Error, wrong number of arguments.\n");
		exit(0);
	}
	i = ft_strlen(av[1]);
	if (i < 4)
	{
		printf("Error, the map doesn't exist. Please enter a valid file\n");
		exit(0);
	}
	i--;
	if ((av[1][i] != 'r') || (av[1][i - 1] != 'e') || (av[1][i - 2] != 'b')
		|| (av[1][i - 3] != '.'))
	{
		printf("Error, the map have to finish in .ber.\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.i = 0;
	data.str = NULL;
	fd = open(av[1], O_RDONLY);
	ft_check_arg(ac, av, fd);
	data = ft_parsing(fd, data);
	data = ft_new_window(data);
	data = ft_load(data, 30);
	ft_aff_map(data);
	mlx_key_hook(data.mlx_win, ft_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_mouse_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
