/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:44:23 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/16 06:40:45 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

char	*score_to_str(t_level *l)
{
	char	*res;
	char	*scr;
	char	*mx;

	scr = ft_itoa(l->player.coins);
	mx = ft_itoa(l->data.coins_max);
	res = add_str(scr, "/");
	res = add_str(res, mx);
	return (res);
}

void	hud_info(t_level *l, char *s)
{
	int	margin;

	draw_hud(l);
	mlx_string_put(l->params.mlx, l->params.mlx_win, 10, 21, 0xFFFFFF, add_str("level: ", l->name));
	margin = (ft_strlen(l->name) + 7) * 10;
	mlx_string_put(l->params.mlx, l->params.mlx_win, margin, 21, 0xFFFFFF, s);
}