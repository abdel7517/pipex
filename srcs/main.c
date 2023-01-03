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
#include <time.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		error;
	int		wait_status;
	int		status_code;
	int		file;
	int		i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i++]);
	}

	(void)argc;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		file = open("result.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		error = execve("/usr/bin/ls", argv, envp);
		if (error == -1)
			return (printf("Could not find program to execute.\n"), 0);
	}
	else
	{
		wait(&wait_status);
		if (WIFEXITED(wait_status))
		{
			status_code = WEXITSTATUS(wait_status);
			if (status_code == 0)
				printf("SUCCESS\n");
			else
				printf("Failure with status code %d\n", status_code);
		}
	}
	return (0);
}
