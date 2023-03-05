/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:44 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/05 21:04:41 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*parse_line(char **s)
{
	int		i;
	char	*res;

	i = 0;
	while (s && s[0] && s[0][i] && s[0][i] != '\n')
		i++;
	if (i == (int)ft_strlens(s[0]))
	{
		res = ft_strjoins(s[0], "");
		s[0] = NULL;
		return (res);
	}
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (0);
	i = -1;
	while (s[0][++i] != '\n')
		res[i] = s[0][i];
	s[0] = get_afternewline(s[0]);
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			rd;
	static char	*last_buffer = NULL;

	rd = -1;
	if (last_buffer && ft_strchrs(last_buffer, '\n', rd))
		return (parse_line(&last_buffer));
	while (!ft_strchrs(last_buffer, '\n', rd))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(last_buffer);
			last_buffer = NULL;
			return (0);
		}
		buf[rd] = '\0';
		if (rd != BUFFER_SIZE)
			return (end_nullifier(&last_buffer, buf));
		last_buffer = ft_strjoins(last_buffer, buf);
	}
	return (parse_line(&last_buffer));
}
