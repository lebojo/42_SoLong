/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   console.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/05 14:26:11 by lebojo			#+#	#+#			 */
/*   Updated: 2023/04/01 23:28:52 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "proto.h"

int error(char *str)
{
	ft_putstr_fd("\033[0;31m[ERROR] \033[0m", 0);
	ft_putstr_fd(str, 0);
	ft_putchar_fd('\n', 0);
	return (0);
}

int info(char *str)
{
	ft_putstr_fd("\e[0;32m[", 0);
	ft_putstr_fd(NAME_SHORT, 0);
	ft_putstr_fd("] \033[0m", 0);
	ft_putstr_fd(str, 0);
	ft_putchar_fd('\n', 0);
	return(0);
}

void	print_score(int min, int max)
{
	ft_putnbr_fd(min, 1);
	ft_putchar_fd('/', 1);
	ft_putnbr_fd(max, 1);
	ft_putchar_fd('\n', 1);
}

void	print_pos(char *title, t_vector v)
{
	ft_putstr_fd("\e[0;32m[", 0);
	ft_putstr_fd(title, 0);
	ft_putstr_fd("] \033[0m", 0);
	ft_putstr_fd("\tX: ", 0);
	ft_putnbr_fd(v.x, 0);
	ft_putstr_fd("\tY: ", 0);
	ft_putnbr_fd(v.y, 0);
	ft_putstr_fd("\n", 0);
}