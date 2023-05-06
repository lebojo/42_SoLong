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
# include <mlx.h>

# define NAME "BeachBall life simulator 2023 EXTREME edititon"
# define NAME_SHORT "BBLS2EE"

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
	char	*player;
	char	*exit;
	char	*collect;
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
	char		*map;
	char		**map_matrix;
	int			key[4];
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

/*MOVEMENTS			*/
int			int_to_dir(int	key);
char		move_id(t_vector m_pos, char **map_matrix, char dir);
void		move_draw(t_level *lvl, char dir, char id);
t_vector	pixel_to_matrix(t_vector pos);

/*DRAW				*/
int			draw_player(t_level *l);
void		draw_level(t_level *lvl);

/*PHYSICS			*/
int			physics_process(t_level *l);

/*
MENU
*/

/*START				*/
void		draw_menu(t_level *lvl);

#endif