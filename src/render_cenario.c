/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:19:32 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/12 21:20:19 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	count_collectibles(t_data *info)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	c_count = 0;
	while (i < info->map_data.lines)
	{
		j = 0;
		while (j < info->map_data.columns)
		{
			if (info->map_data.map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	info->map_data.nb_c = c_count;
	return (c_count);
}

void	put_img(t_data *info, int x, int y, char *path)
{	
	info->img.img = mlx_xpm_file_to_image(info->mlx_ptr,
			path, &info->w, &info->h);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_pp,
			&info->img.line_len, &info->img.endian);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img, x, y);
	mlx_destroy_image(info->mlx_ptr, info->img.img);
}

/* Reads the array of strings char by char.
   Put the sprites on screen based in the array  */
void	render(t_data *info)
{
	int		line;
	int		index;
	char	*s;

	line = 0;
	while (line < info->map_data.lines)
	{
		s = info->map_data.map[line];
		index = 0;
		while (index < info->map_data.columns)
		{
			if (s[index] == '0')
				put_img(info, index * BITS, line * BITS, info->paths.ground);
			else if (s[index] == '1')
				put_img(info, index * BITS, line * BITS, info->paths.wall);
			else if (s[index] == 'C')
				put_img(info, index * BITS, line * BITS, info->paths.cole);
			else if (s[index] == 'E')
				put_img(info, index * BITS, line * BITS, info->paths.exit);
			else if (s[index] == 'P')
				put_img(info, index * BITS, line * BITS, info->paths.hero);
			index++;
		}
		line++;
	}
}
