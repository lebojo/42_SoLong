/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:45 by lebojo            #+#    #+#             */
/*   Updated: 2023/04/30 15:01:30 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void	draw_menu(t_level *lvl)
{
	int		w;
	int		h;
	char	*play_but;
	
	play_but = mlx_xpm_file_to_image(lvl->params.mlx, "./assets/start_title.xpm", &w, &h);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, play_but, (lvl->data.size.x * 32 / 2) - 32, (lvl->data.size.y * 32 / 2) - 16);
}

/*
MEC, en fait faut faire une fenêtre pour le menu,
avec un sélection de niveau, et après ça créer une nouvelle
fenêtre.f
*/