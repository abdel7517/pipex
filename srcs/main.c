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


int	check_access(char **paths_splited, char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*cmd_path;
	char	**arg;

	arg = NULL;
	i = 0;
	while (paths_splited[i])
	{
		path = ft_strjoin(paths_splited[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		if (access(cmd_path, X_OK) == 0)
		{

			execve(cmd_path, arg, env);
			ex_err(cmd_path);
		}
		free(cmd_path);
		free(path);
		i++;
	}
	return (-1);
}

int	check_path(char *path, char *cmd, char **env)
{
	char	**paths_splited;
	char	*paths;
	char 	*message_error;

	paths = ft_substr(path, 5, ft_strlen(path) - 5);
	if (paths == NULL)
		return (-1);
	paths_splited = ft_split(paths, ':');
	if (check_access(paths_splited, cmd, env) == -1)
	{
		message_error = ft_strjoin("zsh: command not found: ", cmd);
		ft_error(message_error);
		free(message_error);
		exit(1);
		return (/* free_split(paths_splited),  */free(paths), -1);
	}
	
	// free_split(paths_splited);
	free(paths);
	return (0);
}

int	find_path(char **env, char *cmd)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			if (check_path(env[i], cmd, env) == -1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (-1);
}

void	exec(char *cmd, char **env)
{

	if (ft_strchr(cmd, '/') == NULL)
	{
		find_path(env, cmd);
	}
}

int	pipex(int infile, char *cmd, char **env)
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
			exec(cmd, env);
		return (-1);
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
	pipex(data.infile, argv[2], envp);
	while (i < data.nb_cmd)
	{
		pipex(data.infile, argv[i], envp);
		i++;
	}
	exec(argv[data.nb_cmd], envp);
	return (0);
}
