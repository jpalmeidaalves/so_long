/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:56:59 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/17 21:57:55 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	render_moves_up(t_data *info)
{
	put_img(info, info->map_data.p_col * BITS, info->map_data.p_lin * BITS,
		info->paths.hero);
	if (in_exit(info->map_data.p_lin + 1, info->map_data.p_col, info))
		put_img(info, info->map_data.p_col * BITS, (info->map_data.p_lin + 1)
			* BITS, info->paths.exit);
	else
		put_img(info, info->map_data.p_col * BITS, (info->map_data.p_lin + 1)
			* BITS, info->paths.ground);
}

void	render_moves_down(t_data *info)
{
	put_img(info, info->map_data.p_col * BITS, info->map_data.p_lin * BITS,
		info->paths.hero);
	if (in_exit(info->map_data.p_lin - 1, info->map_data.p_col, info))
		put_img(info, info->map_data.p_col * BITS, (info->map_data.p_lin - 1)
			* BITS, info->paths.exit);
	else
		put_img(info, info->map_data.p_col * BITS, (info->map_data.p_lin - 1)
			* BITS, info->paths.ground);
}

void	render_moves_right(t_data *info)
{
	put_img(info, info->map_data.p_col * BITS, info->map_data.p_lin * BITS,
		info->paths.hero);
	if (in_exit(info->map_data.p_lin, info->map_data.p_col - 1, info))
		put_img(info, (info->map_data.p_col - 1) * BITS, info->map_data.p_lin
			* BITS, info->paths.exit);
	else
		put_img(info, (info->map_data.p_col - 1) * BITS, info->map_data.p_lin
			* BITS, info->paths.ground);
}

void	render_moves_left(t_data *info)
{
	put_img(info, info->map_data.p_col * BITS, info->map_data.p_lin * BITS,
		info->paths.hero);
	if (in_exit(info->map_data.p_lin, info->map_data.p_col + 1, info))
		put_img(info, (info->map_data.p_col + 1) * BITS, info->map_data.p_lin
			* BITS, info->paths.exit);
	else
		put_img(info, (info->map_data.p_col + 1) * BITS, info->map_data.p_lin
			* BITS, info->paths.ground);
}
