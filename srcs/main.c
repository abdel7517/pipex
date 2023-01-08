/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:14:53 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/01 16:14:53 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		nb;

	(void)envp;
	if (check_args(argc, argv, &pipex) == -1)
		return (ft_error("Invalid number of args."), -1);
	open_src(argv, &pipex);
	nb = argc - 3 - pipex.here_doc;
	return (0);
}
