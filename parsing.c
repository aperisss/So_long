/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:00:15 by aperis            #+#    #+#             */
/*   Updated: 2022/02/12 13:34:51 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_check4(char *str, int count, t_data data, char *tmp)
{
	data.i = 0;
	data.len = 0;
	while (str[data.i] != '\n')
		data.i++;
	data.j = data.i;
	data.i++;
	while (str[data.i] && count-- > 1)
	{
		while (str[data.i] != '\n' && str[data.i] != '\0')
		{
			data.i++;
			data.len++;
		}
		if (data.len != data.j)
			ft_error(str, tmp);
		data.len = 0;
		data.i++;
	}
	while (str[data.i++])
		data.len++;
	if (data.len != data.j)
		ft_error(str, tmp);
	free(str);
	return (data);
}

t_data	ft_check3(char *str, int count, char *tmp)
{
	t_data	data;
	int		count4;

	count4 = count;
	data.p_count = 0;
	data.e_count = 0;
	data.c_count = 0;
	data.i = 0;
	while (str[data.i] && count > 0)
	{
		if (str[data.i] == 'P')
			data.p_count++;
		if (str[data.i] == 'E')
			data.e_count++;
		if (str[data.i] == 'C')
			data.c_count++;
		if (str[data.i] == '\n')
			count--;
		data.i++;
	}
	if ((data.c_count < 1) || (data.e_count < 1) || (data.p_count != 1))
		ft_error(str, tmp);
	return (ft_check4(str, count4, data, tmp));
}

t_data	ft_check2(char *str, int count, char *tmp)
{
	t_data	data;
	int		count3;

	count3 = count;
	data.i = 0;
	while (str[data.i] && count > 0)
	{
		if (str[data.i] != '0' && str[data.i] != '1' && str[data.i] != 'C'
			&& str[data.i] != 'P' && str[data.i] != 'E' && str[data.i] != '\n')
			ft_error(str, tmp);
		if (str[data.i] == '\n')
			count--;
		data.i++;
	}
	while (str[data.i] != '\0')
	{
		if (str[data.i] != '1')
			ft_error(str, tmp);
		data.i++;
	}
	return (ft_check3(str, count3, tmp));
}

t_data	ft_check(char *str, int count, char *tmp)
{
	int	i;
	int	count2;

	i = 0;
	count2 = count;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			ft_error(str, tmp);
		i++;
	}
	i = 0;
	while (str[i] && count > 1)
	{
		if (str[i] == '\n')
		{
			count--;
			if (str[i - 1] != '1' || str[i + 1] != '1')
				ft_error(str, tmp);
		}
		i++;
	}
	return (ft_check2(str, count2, tmp));
}

t_data	ft_parsing(int fd, t_data data)
{
	int		count;
	char	*tmp;

	count = 0;
	data.src = get_next_line(fd);
	ft_malloc_error(data.src);
	tmp = NULL;
	while (data.src != NULL)
	{
		data.str = ft_strjoin(data.str, data.src);
		free(data.src);
		data.src = get_next_line(fd);
	}
	tmp = ft_strcpy(tmp, data.str);
	while (data.str[data.i])
	{
		if (data.str[data.i] == '\n')
			count++;
		data.i++;
	}
	data = ft_check(data.str, count, tmp);
	data.count = count + 1;
	data.str = ft_strcpy(data.str, tmp);
	free(tmp);
	return (data);
}
