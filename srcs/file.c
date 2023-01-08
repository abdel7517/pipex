/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:54:07 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/08 11:54:07 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	open_src(char **argv, t_pipex *data)
{	
	if (data->here_doc)
	{
		ft_error("HERE DOC");
	}
	else
	{
		data->infile = open(argv[1], O_RDONLY);
		if (data->infile < 0)
		{
			ex_err("Error on opening infile ");
		}
	}
}

void	open_dest(char *path, t_pipex *data)
{
	if (data->here_doc)
	{
		ft_error("HERE DOC");
	}
	else
	{
		data->outfile = open(path, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (data->outfile < 0)
		{
			ex_err("Error on opening outfile ");
		}
	}
}
