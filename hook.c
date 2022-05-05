/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:39:39 by aperis            #+#    #+#             */
/*   Updated: 2022/01/27 16:13:04 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_w(t_data data)
{
	data.i = 0;
	while (data.str[data.i] != 'P')
		data.i++;
	if (data.str[data.i - data.len - 1] != '1')
	{
		if (data.str[data.i - data.len - 1] == 'E' && data.c_count != 0)
			return (data);
		else if (data.str[data.i - data.len - 1] == 'E' && data.c_count == 0)
		{
			ft_free_all(&data);
			printf("You won !");
			exit(1);
		}
		if (data.str[data.i - data.len - 1] == 'C')
			data.c_count--;
		data.countmove++;
		printf("%d \n", data.countmove);
		data.str[data.i] = '0';
		data.str[data.i - data.len - 1] = 'P';
	}
	return (data);
}

t_data	ft_s(t_data data)
{
	data.i = 0;
	while (data.str[data.i] != 'P')
		data.i++;
	if (data.str[data.i + data.len + 1] != '1')
	{
		if (data.str[data.i + data.len + 1] == 'E' && data.c_count != 0)
			return (data);
		else if (data.str[data.i + data.len + 1] == 'E' && data.c_count == 0)
		{
			ft_free_all(&data);
			printf("You won !");
			exit(1);
		}
		if (data.str[data.i + data.len + 1] == 'C')
			data.c_count--;
		data.countmove++;
		printf("%d \n", data.countmove);
		data.str[data.i] = '0';
		data.str[data.i + data.len + 1] = 'P';
	}
	return (data);
}

t_data	ft_a(t_data data)
{
	data.i = 0;
	while (data.str[data.i] != 'P')
		data.i++;
	if (data.str[data.i - 1] != '1')
	{
		if (data.str[data.i - 1] == 'E' && data.c_count != 0)
			return (data);
		else if (data.str[data.i - 1] == 'E' && data.c_count == 0)
		{
			ft_free_all(&data);
			printf("You won !");
			exit(1);
		}
		if (data.str[data.i - 1] == 'C')
			data.c_count--;
		data.countmove++;
		printf("%d \n", data.countmove);
		data.str[data.i] = '0';
		data.str[data.i - 1] = 'P';
	}
	return (data);
}

t_data	ft_d(t_data data)
{
	data.i = 0;
	while (data.str[data.i] != 'P')
		data.i++;
	if (data.str[data.i + 1] != '1')
	{
		if (data.str[data.i + 1] == 'E' && data.c_count != 0)
			return (data);
		else if (data.str[data.i + 1] == 'E' && data.c_count == 0)
		{
			ft_free_all(&data);
			printf("You won !");
			exit(1);
		}
		if (data.str[data.i + 1] == 'C')
			data.c_count--;
		data.countmove++;
		printf("%d \n", data.countmove);
		data.str[data.i] = '0';
		data.str[data.i + 1] = 'P';
	}
	return (data);
}
