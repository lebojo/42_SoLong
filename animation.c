/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:36:58 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/28 02:40:43 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	anim_player(t_level *l)
{
	if (l->player.vel.x > 0 || l->player.vel.y > 0)
	{
		if (l->texture.pf.nb < l->texture.pf.max)
			l->texture.pf.nb++;
		else
			l->texture.pf.nb = 0;
	}
	if (l->player.vel.x < 0 || l->player.vel.y < 0)
	{
		if (l->texture.pf.nb > 0)
			l->texture.pf.nb--;
		else
			l->texture.pf.nb = l->texture.pf.max;
	}
}

void	anim_coins(t_level *l)
{
	if (l->texture.cf.nb < l->texture.cf.max)
		l->texture.cf.nb++;
	else
		l->texture.cf.nb = 0;
}

void	animation_process(t_level *l)
{
	if (l->time % 3 == 0)
		anim_coins(l);
	if (l->time % 5 == 0)
		anim_player(l);
	l->time++;
}
