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

void	init_pipe(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_pipes)
	{
		if (pipe(&(data->pipes[(i * 2)])) == -1)
			close_free_pipes_pids(data, i);
		i++;
	}
}

void	init(t_pipex *data)
{
	int	i;

	i = 0;
	data->pids = malloc(sizeof(int) * data->nb_pids);
	if (data->pids == NULL)
		ex_err("Error ");
	data->pipes = malloc(sizeof(int *) * (data->nb_pipes * 2));
	if (data->pipes == NULL)
	{
		free(data->pids);
		ex_err("Error ");
	}
}

int	pipex(int infile)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (STDIN_FILENO == infile)
			exit(1);
		else
			execlp("ping", "ping", "-c", "1", "google.com", NULL);
		return(-1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		return (0);
	}
	return (0);
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		i;

	i = 3;
	(void)envp;
	if (check_args(argc, argv, &data) == -1)
		return (ft_error("Invalid number of args."), -1);
	open_src(argv, &data);
	open_dest(argv[argc - 1], &data);
	data.nb_pids = argc - 3 - data.here_doc;
	data.nb_pipes = data.nb_pids + 1;
	data.nb_cmd = argc - 2 - data.here_doc;
	dup2(data.infile, STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	pipex(data.infile);
	while (i < data.nb_cmd)
	{
		pipex(data.infile);
		i++;
	}
	execlp("ping", "ping", "-c", "1", "google.com", NULL);
	ft_error("TEST2");
	return (0);
}
