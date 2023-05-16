/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:42:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/16 06:13:03 by lebojo           ###   ########.fr       */
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
	char		coins;
}	t_data;

typedef struct s_path
{
	char		*empty;
	char		*wall;
	char		*player[4];
	t_range		pf; //pf = player frame
	char		*exit;
	char		*coins[8];
	t_range			cf; //cf = coins frame
	char		*blck;
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
	int	bool_path;
	int	bool_wall;
}	t_requierements;

typedef struct s_player
{
	t_vector	pos;
	int			coins;
	t_vector	vel;
}	t_player;

typedef struct s_level
{
	t_data		data;
	t_path		texture;
	t_player	player;
	t_vector	*collision_map;
	t_vector	*coins_map;
	t_vector	exit;
	int			nb_col;
	char		*map;
	char		**map_matrix;
	int			key[5];
	int			state; // 0 = menu, 1 = niveau 1, etc..
	char		*name;
	t_params	params;
}	t_level;

#endif