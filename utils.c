/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/06 23:34:12 by jchapell		  #+#	#+#			 */
/*   Updated: 2023/05/29 03:06:49 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "inc/proto.h"

void	erase_coins(t_level *l, t_vector pos_erase)
{
	pos_erase.x = (pos_erase.x / l->tx.width) + 1;
	pos_erase.y = (pos_erase.y / l->tx.width) - 1;
	l->map_matrix[pos_erase.y][pos_erase.x] = l->data.empty;
}

char	*add_str(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		ii;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + sizeof(char));
	i = -1;
	ii = 0;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[ii])
		res[i++] = s2[ii++];
	res[i] = '\0';
	return (res);
}

char	*lvl_name_extractor(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (*s != '/' && *s)
		s++;
	s++;
	while (s[i] != '.' && s[i])
		i++;
	res = malloc(sizeof(char) * i);
	i = -1;
	while (s[++i] != '.' && s[i])
		res[i] = s[i];
	return (res);
}

int	check_ext(char *s, char *ext)
{
	int	end_s;
	int	end_ext;

	end_s = ft_strlen(s);
	end_ext = ft_strlen(ext);
	while (s[--end_s] == ext[--end_ext])
		if (end_ext == 0)
			return (1);
	return (0);
}
