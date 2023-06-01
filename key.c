/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:37:31 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 05:03:54 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	key_press(int keycode, t_level *lvl)
{
	if (keycode == 53 || keycode == 65307)
		clean_exit(lvl);
	if (!lvl->key[int_to_dir(keycode)])
	{
		lvl->key[int_to_dir(keycode)] = 1;
		if (lvl->name)
		{
			lvl->player.move++;
			print_move(lvl->player.move);
		}
	}
	return (0);
}

int	key_release(int keycode, t_level *lvl)
{
	if (lvl->key[int_to_dir(keycode)])
		lvl->key[int_to_dir(keycode)] = 0;
	return (0);
}

int	clean_exit(t_level *l)
{
	info("Clean exit");
	if (l->data.coins_max != -1)
		free_level(l);
	exit(info("Game closed"));
}
