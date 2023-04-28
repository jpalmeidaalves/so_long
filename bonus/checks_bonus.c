/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:16:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/17 22:20:29 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	check_devil(int hero_x, int hero_y, t_data *info)
{
	if (hero_x == info->map_data.d_lin && hero_y == info->map_data.d_col)
		close_clean(info);
}

int	in_exit(int hero_x, int hero_y, t_data *info)
{
	if (hero_x == info->map_data.e_lin && hero_y == info->map_data.e_col)
		return (1);
	return (0);
}

void	check_exit(int hero_x, int hero_y, t_data *info)
{
	if (info->map_data.can_exit)
	{
		if (hero_x == info->map_data.e_lin && hero_y == info->map_data.e_col)
			close_clean(info);
	}
}

void	check_no_walls(t_data *info, int i, int j)
{
	if (i == 0 || j == 0 || i == info->map_data.lines - 1
		|| j == info->map_data.columns - 1)
		if (info->map_data.map[i][j] != '1')
			info->map_data.no_walls = 1;
}
