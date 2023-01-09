/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:03:30 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/09 10:03:30 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	exec_path(char **paths_splited, char **env, char **args)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (paths_splited[i])
	{
		path = ft_strjoin(paths_splited[i], "/");
		if (path == NULL)
			ex_err("Error.");
		cmd_path = ft_strjoin(path, args[0]);
		if (cmd_path == NULL)
			ex_err("Error.");
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(paths_splited);
			execve(cmd_path, args, env);
		}
		free(cmd_path);
		free(path);
		i++;
	}
}

int	check_access(char **paths_splited, char *cmd, char **env)
{
	char	**args;

	args = get_args(cmd);
	if (args == NULL)
		ex_err("Error.");
	exec_path(paths_splited, env, args);
	free_split(paths_splited);
	free_split(args);
	return (-1);
}

int	check_path(char *path, char *cmd, char **env)
{
	char	**paths_splited;
	char	*paths;

	paths = ft_substr(path, 5, ft_strlen(path) - 5);
	if (paths == NULL)
		ex_err("Error.");
	paths_splited = ft_split(paths, ':');
	if (paths_splited == NULL)
	{
		free(paths);
		ex_err("Error.");
	}
	free(paths);
	if (check_access(paths_splited, cmd, env) == -1)
		error_message(path, paths_splited, cmd);
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

void	check_cmd(char *cmd, char **env)
{
	char	**args;
	char	*message_error;

	if (ft_strchr(cmd, '/') == NULL)
	{
		find_path(env, cmd);
	}
	else
	{
		args = get_args(cmd);
		execve(args[0], args, env);
		message_error = ft_strjoin("command not found: ", cmd);
		ft_error(message_error);
		free_split(args);
		free(message_error);
		exit(1);
	}
}
