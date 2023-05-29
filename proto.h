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

# include "inc/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "inc/minilibx_macos/mlx.h"
# include "struct.h"

# define NAME "BeachBall in a park simulator 2023 XTREME EDITION"
# define NAME_SHORT "BBIAPS"

/*INIT.C			*/
void		init_level(t_level *level);
void		init_player_frames(t_level *l);
void		init_coins_frames(t_level *l);
void		init_ls(t_level *l);

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
void		collision(t_level *l, t_vector pos, t_vector edge);
void		player_process(t_level *l);
void		collect_coins(t_level *l);
void		exit_level(t_level *l);

/*DRAW				*/
int			draw_player(t_level *l);
void		draw_level(t_level *lvl);
void		draw_screen(t_level *l);
void 		draw_bcgk(t_level *lvl, t_vector start, t_vector end);
void 		draw_hud(t_level *l);
void		draw_around_player(t_level *l);

/*PHYSICS			*/
int			physics_process(t_level *l);
void		move_player(t_level *l);

/*UTILS				*/
void		set_vector(t_vector *v, int x, int y);
int			vector_collide(t_vector v1, t_vector v2, int width);
void		erase_coins(t_level *l, t_vector pos_erase);
t_vector 	vector(int x, int y);
char		*add_str(char *s1, char *s2);
char		*lvl_name_extractor(char *s);
int			check_ext(char *s, char *ext);
int			near_32(int num);
int			abs(int	num);
int			near_0(int num);

/*MATRIX			*/
void		add_collision(t_level *l, t_vector pos, int nb_col);
void		add_coins(t_level *l, t_vector pos, int nb_coins);

/*KEY				*/
int			key_press(int keycode, t_level *lvl);
int			key_release(int keycode, t_level *lvl);

/*ANIMATION			*/
void		animation_process(t_level *l);

/*HUD				*/
void		hud_info(t_level *l, char *s);
char		*score_to_str(t_level *l);

/*VALIDITY			*/
int			can_collect_coins(t_level *l);

/*
MENU
*/

/*START				*/
void		draw_menu(t_level *lvl);
int			menu_process(t_level *l);
void		reset_keys(t_level *lvl);

/*LEVEL_SELECTOR	*/
void		start_menu(t_level *l);

#endif