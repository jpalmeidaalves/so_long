/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:20:25 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/06 19:42:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	free_maps(t_data *info)
{
	int	line;

	line = 0;
	while (line < info->map_data.lines)
	{
		free(info->map_data.map[line]);
		line++;
	}
	free(info->map_data.map);
	line = 0;
	while (line < info->map_data.lines)
	{
		free(info->map_data.map_copy[line]);
		line++;
	}
	free(info->map_data.map_copy);
}

int	close_clean(t_data *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_display(info->mlx_ptr);
	free(info->mlx_ptr);
	free_maps(info);
	print_credits();
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	exit_error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	exit_free_maps_msg(t_data *info, char *msg)
{
	free_maps(info);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
