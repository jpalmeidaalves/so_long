/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:19:29 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/28 17:12:40 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	move_up(t_data *info, int p_lin, int p_col)
{
	info->paths.hero = HERO_R;
	if (info->map_data.map[p_lin - 1][p_col] == 'E')
		info->paths.hero = HERO_DOOR_L;
	if (info->map_data.map[p_lin - 1][p_col] != '1')
	{
		if (in_exit(info->map_data.p_lin, info->map_data.p_col, info))
		{
			info->map_data.map[p_lin - 1][p_col] = 'P';
			info->map_data.p_lin--;
			info->paths.hero = HERO_R;
		}
		update_map_up(info, p_lin, p_col);
		render_moves_up(info);
		info->moves++;
	}
	put_text(info);
	if (!count_collectibles(info))
		info->map_data.can_exit = 1;
	if (in_exit(info->map_data.p_lin, info->map_data.p_col, info)
		&& (info->map_data.can_exit))
		close_clean(info);
	check_devil(info->map_data.p_lin, info->map_data.p_col, info);
}

void	move_down(t_data *info, int p_lin, int p_col)
{
	info->paths.hero = HERO_R;
	if (info->map_data.map[p_lin + 1][p_col] == 'E')
		info->paths.hero = HERO_DOOR_R;
	if (info->map_data.map[p_lin + 1][p_col] != '1')
	{
		if (in_exit(info->map_data.p_lin, info->map_data.p_col, info))
		{
			info->map_data.map[p_lin + 1][p_col] = 'P';
			info->map_data.p_lin++;
			info->paths.hero = HERO_R;
		}
		update_map_down(info, p_lin, p_col);
		render_moves_down(info);
		info->moves++;
	}
	put_text(info);
	if (!count_collectibles(info))
		info->map_data.can_exit = 1;
	if (in_exit(info->map_data.p_lin, info->map_data.p_col, info)
		&& (info->map_data.can_exit))
		close_clean(info);
	check_devil(info->map_data.p_lin, info->map_data.p_col, info);
}

void	move_right(t_data *info, int p_lin, int p_col)
{
	info->paths.hero = HERO_R;
	if (info->map_data.map[p_lin][p_col + 1] == 'E')
		info->paths.hero = HERO_DOOR_R;
	if (info->map_data.map[p_lin][p_col + 1] != '1')
	{
		if (in_exit(info->map_data.p_lin, info->map_data.p_col, info))
		{
			info->map_data.map[p_lin][p_col + 1] = 'P';
			info->map_data.p_col++;
			info->paths.hero = HERO_R;
		}
		update_map_right(info, p_lin, p_col);
		render_moves_right(info);
		info->moves++;
	}
	put_text(info);
	if (!count_collectibles(info))
		info->map_data.can_exit = 1;
	check_exit(info->map_data.p_lin, info->map_data.p_col, info);
	check_devil(info->map_data.p_lin, info->map_data.p_col, info);
}

void	move_left(t_data *info, int p_lin, int p_col)
{
	info->paths.hero = HERO_L;
	if (info->map_data.map[p_lin][p_col - 1] == 'E')
		info->paths.hero = HERO_DOOR_L;
	if (info->map_data.map[p_lin][p_col - 1] != '1')
	{
		if (in_exit(info->map_data.p_lin, info->map_data.p_col, info))
		{
			info->map_data.map[p_lin][p_col - 1] = 'P';
			info->map_data.p_col--;
			info->paths.hero = HERO_L;
		}
		update_map_left(info, p_lin, p_col);
		render_moves_left(info);
		info->moves++;
	}
	put_text(info);
	if (!count_collectibles(info))
		info->map_data.can_exit = 1;
	if (in_exit(info->map_data.p_lin, info->map_data.p_col, info)
		&& (info->map_data.can_exit))
		close_clean(info);
	check_devil(info->map_data.p_lin, info->map_data.p_col, info);
}

void	make_move(t_data *info, int key, int p_lin, int p_col)
{
	if (key == UP)
		move_up(info, p_lin, p_col);
	if (key == DOWN)
		move_down(info, p_lin, p_col);
	if (key == RIGHT)
		move_right(info, p_lin, p_col);
	if (key == LEFT)
		move_left(info, p_lin, p_col);
}
