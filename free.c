/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:05:41 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 05:08:58 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	free_matrix(int max, char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (++i < max)
		free(matrix[i]);
	free(matrix);
}

void	free_level(t_level *l)
{
	free_matrix(l->data.size.y, l->map_matrix);
	free(l->name);
	free(l->map);
	free(l->map_c);
	if (l->nb_col > 0)
		free(l->collision_map);
	if (l->nb_en> 0)
		free(l->enemy_map);
}
