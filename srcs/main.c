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

int	pipex(int infile, char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		return (0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (STDIN_FILENO == infile)
			exit(1);
		else
			check_cmd(cmd, env);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		i;

	i = 3;
	if (check_args(argc, argv, &data) == -1)
		return (ft_error("Invalid number of args."), -1);
	if (envp[0] == NULL)
		return (ft_error("Env is empty"), -1);
	data.nb_cmd = argc - 2 - data.here_doc;
	if (data.here_doc == 0)
	{
		open_src(argv, &data);
		open_dest(argv[argc - 1], &data);
		dup2(data.infile, STDIN_FILENO);
		dup2(data.outfile, STDOUT_FILENO);
		pipex(data.infile, argv[2], envp);
		while (i < data.nb_cmd)
			pipex(data.infile, argv[i++], envp);
		check_cmd(argv[data.nb_cmd], envp);
	}
	else
		ft_error("TODO Here_Doc");
	return (0);
}
