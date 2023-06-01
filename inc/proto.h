/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:47:12 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 18:47:13 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
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
int			coin_check(t_vector pos, t_vector max, char **map);
void		level_validity(t_level *l);

/*CONSOLE			*/
int			error(char *str);
int			info(char *str);
void		print_move(int m);
void		print_score(int min, int max);

/*BUILD				*/
int			build_matrix(t_level *lvl);
void		start_level(t_level *lvl, char *path);

/*MOVEMENTS			*/
int			int_to_dir(int key);
void		collision(t_level *l, t_vector pos, t_vector edge);
void		collect_coins(t_level *l);
void		exit_level(t_level *l);

/*DRAW				*/
int			draw_player(t_level *l);
void		draw_level(t_level *lvl);
void		draw_screen(t_level *l);
void		draw_bcgk(t_level *lvl, t_vector start, t_vector end);
void		draw_hud(t_level *l);
void		draw_image(t_level *l, char *path, t_vector p);
void		draw_wall(t_level *l);
int			draw_cell(t_level *lvl, char c, t_vector pos);

/*PHYSICS			*/
void		friction(t_level *l);
void		move_player(t_level *l);

/*UTILS				*/
void		set_vector(t_vector *v, int x, int y);
int			vector_collide(t_vector v1, t_vector v2, int width);
void		erase_coins(t_level *l, t_vector pos_erase);
t_vector	vector(int x, int y);
char		*add_str(char *s1, char *s2, int f);
char		*lvl_name_extractor(char *s);
int			check_ext(char *s, char *ext);
void		*path_to_image(t_level *l, char *path);
void		create_new_window(t_level *l, t_vector size);

/*MATRIX			*/
void		add_collision(t_level *l, t_vector pos, int nb_col);
void		add_coins(t_level *l, t_vector pos, int nb_coins);
void		add_enemy(t_level *l, t_vector pos, int nb_en);

/*KEY				*/
int			key_press(int keycode, t_level *lvl);
int			key_release(int keycode, t_level *lvl);
int			clean_exit(t_level *l);

/*ANIMATION			*/
void		anim_coins(t_level *l);
void		anim_player(t_level *l);

/*HUD				*/
void		hud_info(t_level *l, char *s);
char		*score_to_str(t_level *l);

/*VALIDITY			*/
int			can_collect_coins(t_level *l);

/*PROCESS			*/
int			level_selector_process(t_level *l);
void		animation_process(t_level *l);
int			physics_process(t_level *l);
void		player_process(t_level *l);

/*FREE				*/
void		free_matrix(int max, char **matrix);
void		free_level(t_level *l);

/*
MENU
*/

/*START				*/
void		draw_menu(t_level *lvl);
int			menu_process(t_level *l);
void		reset_keys(t_level *lvl);

/*LEVEL_SELECTOR	*/
void		start_menu(t_level *l);
void		draw_menu_level(t_level *l, t_vector *p);
void		player_position(t_level *l);
void		launch_level(t_level *l);

#endif