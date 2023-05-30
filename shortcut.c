/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:21:33 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 04:21:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	*path_to_image(t_level *l, char *path)
{
	t_vector	wh;

	return (mlx_xpm_file_to_image(l->prm.mlx, path, &wh.x, &wh.y));
}

void	create_new_window(t_level *l, t_vector size)
{
	l->prm.mlx_win = mlx_new_window(l->prm.mlx, size.x, size.y, NAME);
}
