/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:21:35 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/28 18:48:07 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	print_credits(void)
{
	ft_printf("PIXEL ART CREDITS:\n");
	ft_printf("Hero sprite is Light bandit by Sven Thole obtained in itch.io\n");
	ft_printf("\n                  GAME OVER\n");
}

int	handle_keyboard(int key, t_data *info )
{
	if (key == ESC)
		close_clean(info);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		make_move(info, key, info->map_data.p_lin, info->map_data.p_col);
	return (0);
}

void	start_paths(t_data *info)
{
	info->paths.hero = HERO_R;
	info->paths.wall = WALL;
	info->paths.exit = DOOR;
	info->paths.cole = COLE;
	info->paths.ground = GROUND;
}

void	start_info(t_data *info)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->map_data.columns * BITS,
			info->map_data.lines * BITS, "so_long");
	if (info->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	info->moves = 0;
	start_paths(info);
}

int	main(int ac, char **av)
{
	t_data	info;	

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long [map path]");
		return (0);
	}
	info.map_data.path = av[1];
	read_map(&info);
	start_info(&info);
	render(&info);
	mlx_hook(info.win_ptr, 02, 1L << 0, handle_keyboard, &info);
	mlx_hook(info.win_ptr, 17, 0, &close_clean, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
