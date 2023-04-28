/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:21:02 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/17 22:17:55 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

static void	map_set(char c, t_data *info, int i, int j)
{
	if (c != 'C' && c != '1' && c != 'E' && c != 'P' && c != '0' && c != 'D')
		info->map_data.ilegal_char = 1;
	if (c == 'C')
		info->map_data.nb_c++;
	if (c == 'E')
	{
		info->map_data.nb_e++;
		info->map_data.e_lin = i;
		info->map_data.e_col = j;
	}
	if (c == 'P')
	{
		info->map_data.nb_p++;
		info->map_data.p_lin = i;
		info->map_data.p_col = j;
	}
	if (c == 'D')
	{
		info->map_data.nb_d++;
		info->map_data.d_lin = i;
		info->map_data.d_col = j;
	}
	check_no_walls(info, i, j);
}

static void	check_map(t_data *info)
{
	if (info->map_data.nb_c < 1)
		exit_free_maps_msg(info, "Error: Map has no collectibles");
	if (info->map_data.nb_p != 1)
		exit_free_maps_msg(info,
			"Error: Map has more or less than one start point");
	if (info->map_data.nb_e != 1)
		exit_free_maps_msg(info, "Error: Map has more or less than one exit");
	if (info->map_data.no_walls == 1)
		exit_free_maps_msg(info, "Error: Map is not surrounded by walls");
	if (info->map_data.ilegal_char == 1)
		exit_free_maps_msg(info, "Error: Ilegal char in map");
	if (info->map_data.not_rect == 1)
		exit_free_maps_msg(info, "Error: Map isn't rectangular");
	is_valid_path(info);
}

/* Creates a bidimensional array of chars with the information from the map*/
static void	create_map_arr(t_data *info, int lin, int col)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	info->map_data.map = malloc(sizeof(char *) * info->map_data.lines);
	info->map_data.map_copy = malloc(sizeof(char *) * info->map_data.lines);
	fd = open(info->map_data.path, O_RDONLY);
	while (i < lin)
	{
		j = 0;
		info->map_data.map[i] = get_next_line(fd);
		info->map_data.map_copy[i] = ft_strdup(info->map_data.map[i]);
		while (j < col)
		{
			map_set(info->map_data.map[i][j], info, i, j);
			j++;
		}
		if (!info->map_data.map[i])
			break ;
		i++;
	}
	close(fd);
	check_map(info);
}

void	start_map_data(t_data *info)
{
	info->map_data.lines = 0;
	info->map_data.nb_p = 0;
	info->map_data.nb_e = 0;
	info->map_data.nb_c = 0;
	info->map_data.nb_d = 0;
	info->map_data.ilegal_char = 0;
	info->map_data.no_walls = 0;
	info->map_data.can_exit = 0;
	info->map_data.not_rect = 0;
}

/* Open the document and starts the info struct parameters: line and columns.
   Then call the start_cenario function that will use these data*/
void	read_map(t_data *info)
{
	int		fd;
	char	*line;

	fd = open(info->map_data.path, O_RDONLY);
	if (fd == -1)
		exit_error();
	check_file_name(info->map_data.path);
	line = get_next_line(fd);
	start_map_data(info);
	info->map_data.columns = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (((int)ft_strlen(line) - 1) != info->map_data.columns))
			info->map_data.not_rect = 1;
		info->map_data.lines++;
	}
	close(fd);
	create_map_arr(info, info->map_data.lines, info->map_data.columns);
}
