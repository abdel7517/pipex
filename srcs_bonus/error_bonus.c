/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:06:22 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/08 12:06:22 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
}

void	ex_err(char *str)
{
	perror(str);
	exit (1);
}
