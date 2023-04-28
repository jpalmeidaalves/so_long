/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vill_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:52:10 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/28 17:17:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	move_vill(t_data *info)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 20;
	if (nb < 5)
		move_v_right(info);
	else if (nb < 10)
		move_v_left(info);
	else if (nb < 15)
		move_v_up(info);
	else if (nb < 20)
		move_v_down(info);
}

int	vill_animation(t_data *info)
{
	static int	count;
	static int	index;

	count++;
	if (count % 10000 == 0)
	{
		info->paths.devil = info->anim[index++];
		put_img(info, info->map_data.d_col * BITS, info->map_data.d_lin * BITS,
			info->paths.devil);
	}
	if (count == 60000)
	{
		move_vill(info);
		count = 0;
		index = 0;
	}
	return (0);
}
