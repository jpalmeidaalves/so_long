/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:52:00 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/06 20:59:52 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_file_name(char *file)
{
	file++;
	while (*file != '.')
		file++;
	if (ft_strncmp(file, ".ber", 4))
		exit_error_msg("Error: Not a .ber file");
}

static void	ff(char **arr, int i, int j)
{
	if (arr[i][j] != '1')
	{
		arr[i][j] = '1';
		ff(arr, i, j + 1);
		ff(arr, i, j - 1);
		ff(arr, i + 1, j);
		ff(arr, i - 1, j);
	}
}

void	is_valid_path(t_data *info)
{
	int	i;
	int	j;

	ff(info->map_data.map_copy, info->map_data.p_lin, info->map_data.p_col);
	i = 0;
	while (i < info->map_data.lines)
	{
		j = 0;
		while (j < info->map_data.columns)
		{
			if (info->map_data.map_copy[i][j] == 'E'
				|| info->map_data.map_copy[i][j] == 'C')
			{
				free_maps(info);
				exit_error_msg("There's not a valid path in the map");
			}
			j++;
		}
		i++;
	}
}
