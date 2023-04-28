/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conflict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:16:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/17 21:23:52 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

int	in_exit(int hero_x, int hero_y, t_data *info)
{
	if (hero_x == info->map_data.e_lin && hero_y == info->map_data.e_col)
		return (1);
	return (0);
}

void	check_exit(int hero_x, int hero_y, t_data *info)
{
	if (hero_x == info->map_data.e_lin && hero_y == info->map_data.e_col
		&& info->map_data.can_exit == 1)
		close_clean(info);
}
