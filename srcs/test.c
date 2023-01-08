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

#define PROCESS_NUM 3

int	main(int argc, char **argv)
{
	int	nb;

	(void)argv;
	nb = argc - 3;
	int	pids[nb];
	int	pipes[nb + 1][2];
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < (nb + 1))
	{
		if (pipe(pipes[i]) == -1)
			return (-1);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (-2);
		if (pids[i] == 0)
		{
			j = 0;
			while (j < (nb + 1))
			{
				if (i != j)
					close(pipes[j][0]);
				if (i + 1 != j)
					close(pipes[j][1]);
				j++;
			}
			if (read(pipes[i][0], &x, sizeof(int)) == -1)
				return (-1);
			x++;
			if (write(pipes[i + 1][1], &x, sizeof(int)) == -1)
				return (-1);
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return (0);
		}
		i++;
	}
	y = 0;
	j = 0;
	while (j < (nb + 1))
	{
		if (nb != j)
			close(pipes[j][0]);
		if (j != 0)
			close(pipes[j][1]);
		j++;
	}
	if (write(pipes[0][1], &y, sizeof(int)) == -1)
		return (-1);
	if (read(pipes[nb][0], &y, sizeof(int)) == -1)
		return (-1);
	close(pipes[0][1]);
	close(pipes[nb][1]);
	printf("Result : %d\n", y);
	i = 0;
	while (i < nb)
	{
		wait(NULL);
		i++;
	}
	return (0);
}