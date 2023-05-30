/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:19:22 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 04:19:23 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	file_char_len(char *file_path)
{
	int		file;
	int		i;
	char	buffer;

	file = open(file_path, O_RDONLY);
	i = 0;
	if (file == -1)
		return (0);
	while (read(file, &buffer, sizeof(char)) != 0)
		i++;
	close(file);
	return (i);
}

void	parse(char *file_path, t_level *lvl)
{
	int		file;
	int		i;
	char	buffer;

	lvl->map = malloc(sizeof(char) * file_char_len(file_path));
	file = open(file_path, O_RDONLY);
	i = 0;
	if (file == -1)
		return ;
	info("Parsing map...");
	if (check_ext(file_path, ".ber") == 0)
		exit(error("A map <.ber> expected"));
	while (read(file, &buffer, sizeof(char)) != 0)
	{
		lvl->map[i++] = buffer;
		if (buffer == '\n')
		{
			if (lvl->data.size.x == -1)
				lvl->data.size.x = i - 1;
			lvl->data.size.y++;
		}
	}
	lvl->map[i] = '\0';
	close(file);
	info("Map parsed");
}
