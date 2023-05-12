/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   proto.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/20 08:48:50 by lebojo			#+#	#+#			 */
/*   Updated: 2023/04/02 00:06:58 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# define NAME "BeachBall in a park simulator 2023 XTREME EDITION"
# define NAME_SHORT "BBIAPS"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_data
{
	t_vector	size;
	int			coins_max;
	char		empty;
	char		wall;
	char		player;
	char		exit;
	char		collect;
}	t_data;

typedef struct s_path
{
	char	*empty;
	char	*wall;
	char	*player[4];
	char	*exit;
	char	*collect;
	char	*blck;
	int		width;
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
	int			state; // 0 = menu, 1 = ig
	t_params	params;
}	t_level;

/*MAIN.C			*/
void		init_level(t_level *level);

/*PARSE.C			*/
void		parse(char *file_path, t_level *lvl);

/*VALIDITY			*/
int			parse_validity(t_level lvl);

/*CONSOLE			*/
int			error(char *str);
int			info(char *str);
void		print_score(int min, int max);
void		print_pos(char *title, t_vector v);

/*BUILD				*/
int			build_matrix(t_level *lvl);
void		start_level(t_level *lvl, char *path);
void		add_collision(t_level *l, t_vector pos, int nb_col);

/*MOVEMENTS			*/
int			int_to_dir(int	key);
t_vector	collision(t_level *l, t_vector pos, t_vector edge);
void		player_process(t_level *l);
void		collect_coins(t_level *l);
void	exit_level(t_level *l);

/*DRAW				*/
int			draw_player(t_level *l);
void		draw_level_behind(t_level *lvl);
void		draw_level_front(t_level *lvl);
void		draw_screen(t_level *l);

/*PHYSICS			*/
int			physics_process(t_level *l);
void		move_player(t_level *l);

/*UTILS				*/
void		set_vector(t_vector *v, int x, int y);
int			vector_collide(t_vector v1, t_vector v2, int width);
int			invert(int d);
void		erase_coins(t_level *l, t_vector pos_erase);
t_vector 	vector(int x, int y);

/*MATRIX			*/
void		add_collision(t_level *l, t_vector pos, int nb_col);
void		add_coins(t_level *l, t_vector pos, int nb_coins);

/*KEY				*/
int			key_press(int keycode, t_level *lvl);
int			key_release(int keycode, t_level *lvl);

/*
MENU
*/

/*START				*/
void		draw_menu(t_level *lvl);
void		menu_process(t_level *l);

#endif