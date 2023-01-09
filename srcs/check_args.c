/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:50:50 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/08 11:50:50 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	has_heredoc(char *first_arg)
{
	if (first_arg != NULL)
	{
		if (ft_strncmp("here_doc", first_arg, 9) == 0)
			return (1);
		return (0);
	}
	return (0);
}

int	check_args(int argc, char **argv, t_pipex *data)
{
	if (has_heredoc(argv[1]))
	{
		data->here_doc = 1;
		if (argc < 6)
			return (-1);
	}
	else
	{
		data->here_doc = 0;
		if (argc < 5)
			return (-1);
	}
	return (0);
}

char	**get_args(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (args == NULL)
		return (NULL);
	return (args);
}

void	error_message(char *paths, char **paths_splited, char *cmd)
{
	char	*message_error;

	message_error = ft_strjoin("command not found: ", cmd);
	if (message_error == NULL)
	{
		free(paths_splited);
		free(paths);
		ex_err("Error.");
	}
	ft_error(message_error);
	free(message_error);
	exit(1);
}
