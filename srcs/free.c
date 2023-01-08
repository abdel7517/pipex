/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:04:48 by abchaban          #+#    #+#             */
/*   Updated: 2023/01/08 16:50:41 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	close_pipes(t_pipex *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(data->pipes[(i * 2) + 0]);
		close(data->pipes[(i * 2) + 1]);
		i++;
	}
}

void	close_free_pipes_pids(t_pipex *data, int size)
{
	free(data->pids);
	free(data->pipes);
	close_pipes(data, size);
	ex_err("Error ");
}