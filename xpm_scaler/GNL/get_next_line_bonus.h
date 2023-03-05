/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:51 by jchapell          #+#    #+#             */
/*   Updated: 2022/12/22 05:02:15 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c, int rd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_afternewline(char *s1);
size_t	ft_strlen(const char *str);
char	*end_nullifier(char **s1, char *s2);
char	*parse_line(char **s);
void	wich_fd(int fd, char *buf, int rd);
int		ft_tab_copy(char **tab, char **tab2);
int		tab_len(char **tab);

#endif