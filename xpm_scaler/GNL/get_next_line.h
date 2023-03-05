/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:51 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/05 21:00:46 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
int		ft_strchrs(const char *s, int c, int rd);
char	*ft_strjoins(char const *s1, char const *s2);
char	*get_afternewline(char *s1);
size_t	ft_strlens(const char *str);
char	*end_nullifier(char **s1, char *s2);
char	*parse_line(char **s);

#endif