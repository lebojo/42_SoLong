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
	void	*mlx;
	void	*mlx_win;
	void	*img;
}	t_params;

typedef struct s_requierements
{
	int	bool_player;
	int	bool_exit;
	int	bool_coins;
}	t_requierements;

typedef struct s_level
{
	t_data	data;
	t_path	texture;
	char	*map;
}	t_level;



/*PARSE.C			*/
char		*parse(char *file_path);
t_vector	map_size(char *map);

/*VALIDITY			*/
int			parse_validity(t_level lvl);

/*CONSOLE			*/
int			error(char *str);
int			info(char *str);

/*BUILD				*/
void		build_level(t_level lvl, t_params prm);

#endif