/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:50 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/20 10:22:20 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int		size;
	char	empty;
	char	wall;
	char	player;
	char	exit;
	char	collect;
}	t_data;

typedef struct s_requierements
{
	int	bool_player;
	int	bool_exit;
	int	bool_coins;
}	t_requierements;

typedef struct s_level
{
	t_data	data;
	char	*map;
}	t_level;

/*PARSE.C			*/
char	*parse(char *file_path);

/*VALIDITY			*/
int		parse_validity(t_level lvl);
#endif