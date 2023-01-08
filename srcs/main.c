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

int	pipex(t_pipex *data)
{
	int	i;

	i = 0;
	data->pids = malloc(sizeof(int) * data->nb_pids);
	if (data->pids == NULL)
	{
		ft_error("Error.");
		exit(1);
	}
	data->pipes = malloc(sizeof(int *) * (data->nb_pipes));
	if (data->pipes == NULL)
	{
		free(data->pids);
		ft_error("Error.");
		exit(1);
	}
	while (i < data->nb_pipes)
	{
		data->pipes[i] = malloc(sizeof(int) * 2);
		if (data->pipes == NULL)
		{
			free(data->pids);
			ft_error("Error.");
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	(void)envp;
	if (check_args(argc, argv, &data) == -1)
		return (ft_error("Invalid number of args."), -1);
	open_src(argv, &data);
	data.nb_pids = argc - 3 - data.here_doc;
	data.nb_pipes = data.nb_pids + 1;
	pipex(&data);
	return (0);
}
