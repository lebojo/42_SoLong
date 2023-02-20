/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:50 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/20 09:07:12 by lebojo           ###   ########.fr       */
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

typedef struct s_level
{
	t_data	data;
	char	*map;
}	t_level;

/*PARSE.C			*/
char	*parse(char *file_path);

#endif