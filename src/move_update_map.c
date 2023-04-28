/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_frames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:36:44 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/17 21:56:03 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	update_map_up(t_data *info, int p_lin, int p_col)
{
	if (info->map_data.map[p_lin - 1][p_col] == '0' || info->map_data.map[p_lin
		- 1][p_col] == 'C')
	{
		info->map_data.map[p_lin - 1][p_col] = 'P';
		info->map_data.map[p_lin][p_col] = '0';
		if (info->map_data.map[p_lin - 1][p_col] == 'C')
			info->map_data.nb_c--;
		info->map_data.p_lin--;
	}
	if (info->map_data.map[p_lin - 1][p_col] == 'E')
	{
		info->map_data.map[p_lin][p_col] = '0';
		info->paths.hero = HERO_DOOR_R;
		info->map_data.p_lin--;
	}
}

void	update_map_down(t_data *info, int p_lin, int p_col)
{
	if (info->map_data.map[p_lin + 1][p_col] == '0'
				|| info->map_data.map[p_lin + 1][p_col] == 'C')
	{
		info->map_data.map[p_lin + 1][p_col] = 'P';
		info->map_data.map[p_lin][p_col] = '0';
		if (info->map_data.map[p_lin - 1][p_col] == 'C')
			info->map_data.nb_c--;
		info->map_data.p_lin++;
	}
	if (info->map_data.map[p_lin + 1][p_col] == 'E')
	{
		info->map_data.map[p_lin][p_col] = '0';
		info->paths.hero = HERO_DOOR_R;
		info->map_data.p_lin++;
	}
}

void	update_map_right(t_data *info, int p_lin, int p_col)
{
	if (info->map_data.map[p_lin][p_col + 1] == '0'
				|| info->map_data.map[p_lin][p_col + 1] == 'C')
	{
		info->map_data.map[p_lin][p_col + 1] = 'P';
		info->map_data.map[p_lin][p_col] = '0';
		if (info->map_data.map[p_lin - 1][p_col] == 'C')
			info->map_data.nb_c--;
		info->map_data.p_col++;
	}
	if (info->map_data.map[p_lin][p_col + 1] == 'E')
	{
		info->map_data.map[p_lin][p_col] = '0';
		info->paths.hero = HERO_DOOR_R;
		info->map_data.p_col++;
	}
}

void	update_map_left(t_data *info, int p_lin, int p_col)
{
	if (info->map_data.map[p_lin][p_col - 1] == '0'
				|| info->map_data.map[p_lin][p_col - 1] == 'C')
	{
		info->map_data.map[p_lin][p_col - 1] = 'P';
		info->map_data.map[p_lin][p_col] = '0';
		if (info->map_data.map[p_lin - 1][p_col] == 'C')
			info->map_data.nb_c--;
		info->map_data.p_col--;
	}
	if (info->map_data.map[p_lin][p_col - 1] == 'E')
	{
		info->map_data.map[p_lin][p_col] = '0';
		info->paths.hero = HERO_DOOR_L;
		info->map_data.p_col--;
	}	
}
