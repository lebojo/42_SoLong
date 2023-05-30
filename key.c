/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:37:31 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	key_press(int keycode, t_level *lvl)
{
	lvl->key[int_to_dir(keycode)] = 1;
	return (0);
}

int	key_release(int keycode, t_level *lvl)
{
	lvl->key[int_to_dir(keycode)] = 0;
	return (0);
}
