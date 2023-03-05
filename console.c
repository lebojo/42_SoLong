/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:26:11 by lebojo            #+#    #+#             */
/*   Updated: 2023/03/05 14:40:08 by lebojo           ###   ########.fr       */
/*                                                                            */
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
    ft_putstr_fd("\033[0;31m[", 0);
    ft_putstr_fd(NAME_SHORT, 0);
    ft_putstr_fd("] \033[0m", 0);
    ft_putstr_fd(str, 0);
    ft_putchar_fd('\n', 0);
    return(0);
}