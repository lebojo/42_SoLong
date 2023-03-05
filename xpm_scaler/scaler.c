/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:38:09 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/05 21:15:23 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "GNL/get_next_line.h"

int	main(int argc, char **argv)
{
	char	*tmp;
	int		fd;
	char	*rd;

	fd = open(argv[1], O_RDWR);
	while (rd != 0)
	{
		rd = read(fd, rd,1);
	}
	
	tmp = get_next_line(fd);
	while (ft_strncmp(tmp, "/* pixels */\n", 13) != 0)
	{
		tmp = get_next_line(fd);
		ft_putstr_fd(tmp, 0);
	}
	ft_putstr_fd("non", 0);
	return (0);
}