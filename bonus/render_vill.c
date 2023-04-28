/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_vill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:13:07 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/28 17:16:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	render_vill(t_data *info, char dir)
{
	put_img(info, info->map_data.d_col * BITS, info->map_data.d_lin * BITS,
		info->paths.ground);
	info->map_data.map[info->map_data.d_lin][info->map_data.d_col] = '0';
	if (dir == 'r')
		info->map_data.d_col++;
	if (dir == 'l')
		info->map_data.d_col--;
	if (dir == 'u')
		info->map_data.d_lin--;
	if (dir == 'd')
		info->map_data.d_lin++;
	put_img(info, info->map_data.d_col * BITS, info->map_data.d_lin * BITS,
		info->paths.devil);
	info->map_data.map[info->map_data.d_lin][info->map_data.d_col] = 'D';
}

void	move_v_right(t_data *info)
{
	if (info->map_data.map[info->map_data.d_lin][info->map_data.d_col
		+ 1] == '0')
		render_vill(info, 'r');
	else if (info->map_data.map[info->map_data.d_lin][info->map_data.d_col
		+ 1] == 'P')
	{
		render_vill(info, 'r');
		close_clean(info);
	}
}

void	move_v_left(t_data *info)
{
	if (info->map_data.map[info->map_data.d_lin][info->map_data.d_col
		- 1] == '0')
		render_vill(info, 'l');
	else if (info->map_data.map[info->map_data.d_lin][info->map_data.d_col
		- 1] == 'P')
	{
		render_vill(info, 'l');
		close_clean(info);
	}
}

void	move_v_up(t_data *info)
{
	if (info->map_data.map[info->map_data.d_lin - 1][info->map_data.d_col
	] == '0')
		render_vill(info, 'u');
	else if (info->map_data.map[info->map_data.d_lin - 1][info->map_data.d_col
	] == 'P')
	{
		render_vill(info, 'u');
		close_clean(info);
	}
}

void	move_v_down(t_data *info)
{
	if (info->map_data.map[info->map_data.d_lin + 1][info->map_data.d_col
	] == '0')
		render_vill(info, 'd');
	else if (info->map_data.map[info->map_data.d_lin + 1][info->map_data.d_col
	] == 'P')
	{
		render_vill(info, 'd');
		close_clean(info);
	}
}
