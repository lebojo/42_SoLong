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

#include "inc/proto.h"

int	error(char *str)
{
	ft_putstr_fd("\033[0;31m[ERROR] \033[0m", 0);
	ft_putstr_fd(str, 0);
	ft_putchar_fd('\n', 0);
	return (1);
}

int	info(char *str)
{
	ft_putstr_fd("\e[0;32m[", 0);
	ft_putstr_fd(NAME_SHORT, 0);
	ft_putstr_fd("] \033[0m", 0);
	ft_putstr_fd(str, 0);
	ft_putchar_fd('\n', 0);
	return (1);
}

void	print_move(int m)
{
	ft_putstr_fd("\e[0;32m[", 0);
	ft_putstr_fd("Move", 0);
	ft_putstr_fd("] \033[0m", 0);
	ft_putnbr_fd(m, 1);
	ft_putchar_fd('\n', 1);
}

void	print_score(int min, int max)
{
	ft_putstr_fd("\e[0;32m[", 0);
	ft_putstr_fd("Coins", 0);
	ft_putstr_fd("] \033[0m", 0);
	ft_putnbr_fd(min, 1);
	ft_putchar_fd('/', 1);
	ft_putnbr_fd(max, 1);
	ft_putchar_fd('\n', 1);
}
