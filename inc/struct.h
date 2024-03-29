/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:42:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/06/01 03:56:56 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_range
{
	int	nb;
	int	max;
}	t_range;

typedef struct s_data
{
	t_vector	size;
	int			coins_max;
	char		empty;
	char		wall;
	char		player;
	char		exit;
	char		enemy;
	char		coins;
}	t_data;

typedef struct s_path
{
	char		*empty[2];
	char		*wall;
	char		*enemy;
	char		*player[4];
	t_range		pf;
	char		*exit;
	char		*coins[8];
	t_range		cf;
	char		*blck;
	char		*pb;
	char		*qb;
	char		*logo;
	int			width;
}	t_path;

typedef struct s_params
{
	void		*mlx;
	void		*mlx_win;
}	t_params;

typedef struct s_requierements
{
	int	bool_player;
	int	bool_exit;
	int	bool_coins;
}	t_requierements;

typedef struct s_player
{
	t_vector	pos;
	int			coins;
	int			ls_position;
	int			max_level;
	int			move;
	t_vector	vel;
}	t_player;

typedef struct s_level
{
	t_data		data;
	t_path		tx;
	t_player	player;
	t_vector	*collision_map;
	t_vector	*enemy_map;
	t_vector	*map_c;
	t_vector	exit;
	t_vector	exit_mx;
	int			nb_col;
	int			nb_en;
	char		*map;
	char		**map_matrix;
	int			key[5];
	int			time;
	char		*name;
	t_vector	ls_pos[10];
	char		*ls_09[10];
	char		*ls_09_dark[10];
	t_params	prm;
}	t_level;

#endif