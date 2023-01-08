/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:27:43 by mmrabet           #+#    #+#             */
/*   Updated: 2023/01/01 19:27:43 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./../libft/libft.h"
# include "./../ft_printf/ft_printf.h"

typedef struct s_pipex
{
	pid_t	pid;
	char	**cmd_path;
	char	**cmd_args;
	char	*envp;
	char	*cmd;
	int		pipes[][2];
	int		*pids;
	int		here_doc;
	int		infile;
	int		outfile;
	int		nb_cmd;
	int		nb_pipes;
	int		nb_pids;
	int		index;

}	t_pipex;

void	ft_error(char *str);
int		check_args(int argc, char **argv, t_pipex *data);
int		has_heredoc(char *first_arg);
void	open_src(char **argv, t_pipex *data);
void	ex_err(char *str);

#endif
