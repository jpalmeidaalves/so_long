/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:05:14 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/28 17:22:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define HERO_R "./imgs/hero_0.xpm"
# define HERO_L "./imgs/hero_1.xpm"
# define WALL "./imgs/wall_1.xpm"
# define DOOR "./imgs/wood_door.xpm"
# define COLE "./imgs/collect.xpm"
# define GROUND "./imgs/ground.xpm"
# define HERO_DOOR_R "./imgs/hero_door_right.xpm"
# define HERO_DOOR_L "./imgs/hero_door_left.xpm"
# define DEVIL "./imgs/devil1.xpm"
# define VILL0 "imgs/vill0.xpm"
# define VILL1 "imgs/vill1.xpm"
# define VILL2 "imgs/vill2.xpm"
# define VILL3 "imgs/vill3.xpm"
# define VILL4 "imgs/vill4.xpm"
# define VILL5 "imgs/vill5.xpm"
# define VILL6 "imgs/vill6.xpm"
# define ESC 65307
# define RIGHT 100
# define LEFT 97
# define UP 119
# define DOWN 115
# define NONE 0

# define BITS 64

typedef struct s_paths
{
	char	*hero;
	char	*wall;
	char	*exit;
	char	*cole;
	char	*ground;
	char	*devil;
}			t_paths;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_map
{
	int		lines;
	int		columns;
	char	*path;
	char	**map;
	char	**map_copy;
	int		p_lin;
	int		p_col;
	int		e_lin;
	int		e_col;
	int		d_lin;
	int		d_col;
	int		nb_p;
	int		nb_e;
	int		nb_c;
	int		nb_d;
	int		no_walls;
	int		ilegal_char;
	int		can_exit;
	int		not_rect;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		h;
	int		w;
	void	*img_ptr;
	t_map	map_data;
	int		moves;
	char	*moves_nb_str;
	time_t	time;
	t_paths	paths;
	char	**anim;
}			t_data;

int			close_clean(t_data *data);
void		read_map(t_data *info);
void		exit_error(void);
void		exit_error_msg(char *msg);
void		put_img(t_data *info, int x, int y, char *path);
void		render(t_data *info);
void		make_move(t_data *info, int key, int p_lin, int p_col);
void		ft_print_array(char **array, int nb_lines);
void		check_file_name(char *file);
void		is_valid_path(t_data *info);
int			count_collectibles(t_data *info);
void		free_maps(t_data *info);
void		exit_free_maps_msg(t_data *info, char *msg);
void		print_credits(void);
void		check_devil(int hero_x, int hero_y, t_data *info);
void		check_exit(int hero_x, int hero_y, t_data *info);
int			in_exit(int hero_x, int hero_y, t_data *info);
void		render_moves_up(t_data *info);
void		render_moves_down(t_data *info);
void		render_moves_right(t_data *info);
void		render_moves_left(t_data *info);
void		put_text(t_data *info);
void		check_no_walls(t_data *info, int i, int j);
void		update_map_up(t_data *info, int p_lin, int p_col);
void		update_map_down(t_data *info, int p_lin, int p_col);
void		update_map_right(t_data *info, int p_lin, int p_col);
void		update_map_left(t_data *info, int p_lin, int p_col);
int			vill_animation(t_data *info);
void		move_v_down(t_data *info);
void		move_v_up(t_data *info);
void		move_v_left(t_data *info);
void		move_v_right(t_data *info);

#endif
