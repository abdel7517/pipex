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

#include "./pipex.h"

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
	char	*message_error;

	paths = ft_substr(path, 5, ft_strlen(path) - 5);
	if (paths == NULL)
		return (-1);
	paths_splited = ft_split(paths, ':');
	if (check_access(paths_splited, cmd, env) == -1)
	{
		message_error = ft_strjoin("command not found: ", cmd);
		ft_error(message_error);
		free(message_error);
		exit(1);
		return (free(paths), -1);
	}
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

void	check_cmd(char *cmd, char **env)
{
	// char	**arg;
	// arg = NULL;
	if (ft_strchr(cmd, '/') == NULL)
	{
		find_path(env, cmd);
	}
	else
	{
		// execve(cmd, arg, env);
		// ex_err(cmd);
		ft_error("TODO");
	}
}
