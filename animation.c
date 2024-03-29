/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:36:58 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	anim_player(t_level *l)
{
	if (l->player.vel.x > 0 || l->player.vel.y > 0)
	{
		if (l->tx.pf.nb < l->tx.pf.max)
			l->tx.pf.nb++;
		else
			l->tx.pf.nb = 0;
	}
	else if (l->player.vel.x < 0 || l->player.vel.y < 0)
	{
		if (l->tx.pf.nb > 0)
			l->tx.pf.nb--;
		else
			l->tx.pf.nb = l->tx.pf.max;
	}
}

void	anim_coins(t_level *l)
{
	if (l->tx.cf.nb < l->tx.cf.max)
		l->tx.cf.nb++;
	else
		l->tx.cf.nb = 0;
}
