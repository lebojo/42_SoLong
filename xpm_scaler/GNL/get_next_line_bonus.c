/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:44 by jchapell          #+#    #+#             */
/*   Updated: 2022/12/22 05:03:28 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*parse_line(char **s)
{
	int		i;
	char	*res;

	i = 0;
	while (s && s[0] && s[0][i] && s[0][i] != '\n')
		i++;
	if (i == (int)ft_strlen(s[0]))
	{
		res = ft_strjoin(s[0], "");
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

// void	wich_fd(int fd, char *buf, int rd)
// {
// 	static char	**buf_tab;
// 	char		**temp_tab;

// 	if (tab_len(buf_tab) < fd + 2)
// 	{
// 		temp_tab = malloc(sizeof(char *) * (fd - 2));
// 		ft_tab_copy(buf_tab, temp_tab);
// 		temp_tab[fd - 2] = malloc(sizeof(char) * (ft_strlen(buf) + 1));
// 		temp_tab[fd - 2] = ft_strjoin(buf, "");
// 		printf("New file discovered\n");
// 	}
// 	else
// 		printf("Je la connais deja celle la bro\n");
// }

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			rd;
	static char	*last_buffer[4096];

	rd = -1;
	if (last_buffer[fd] && ft_strchr(last_buffer[fd], '\n', rd))
		return (parse_line(&last_buffer[fd]));
	while (!ft_strchr(last_buffer[fd], '\n', rd))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(last_buffer[fd]);
			last_buffer[fd] = NULL;
			return (0);
		}
		buf[rd] = '\0';
		if (rd != BUFFER_SIZE)
			return (end_nullifier(&last_buffer[fd], buf));
		last_buffer[fd] = ft_strjoin(last_buffer[fd], buf);
	}
	return (parse_line(&last_buffer[fd]));
}
