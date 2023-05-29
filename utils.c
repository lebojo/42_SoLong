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

#include "proto.h"

void	set_vector(t_vector *v, int x, int y)
{
	v->x = x;
	v->y = y;	
}

int vector_collide(t_vector v1, t_vector v2, int width)
{
	int v1Right;
	int v1Bottom;
	int v2Right;;
	int v2Bottom;;

	v1Right = v1.x + width - 2;
	v1Bottom = v1.y + width - 2;
	v2Right = v2.x + width - 5;
	v2Bottom = v2.y + 20;
	set_vector(&v1, v1.x + 2, v1.y + 2);
	set_vector(&v2, v2.x + 5, v2.y + 15);
	if (v1.x <= v2Right && v1Right >= v2.x && v1.y <= v2Bottom && v1Bottom >= v2.y)
		return (1);
	return (0);
}

void	erase_coins(t_level *l, t_vector pos_erase)
{
	pos_erase.x = (pos_erase.x / l->texture.width) + 1;
	pos_erase.y = (pos_erase.y / l->texture.width) - 1;
	l->map_matrix[pos_erase.y][pos_erase.x] = l->data.empty;
}

t_vector vector(int x, int y)
{
	t_vector res;

	res.x = x;
	res.y = y;
	return (res);
}

char		*add_str(char *s1, char *s2)
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

int	near_32(int num)
{
	int quotient = num / 32;
	int multiple = quotient * 32;

	int lower_multiple = multiple;
	int upper_multiple = multiple + 32;

	if (num - lower_multiple < upper_multiple - num) {
		return lower_multiple;
	} else {
		return upper_multiple;
	}
}

int	near_0(int num)
{
	if (num > 0)
		return (2);
	if (num < 0)
		return (-2);
	return (0);	
}

int	abs(int	num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}