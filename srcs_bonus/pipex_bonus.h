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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

typedef struct s_pipex
{
	int		here_doc;
	int		infile;
	int		outfile;
	int		nb_cmd;

}	t_pipex;

size_t	ft_strlen(const char *s);
void	close_free_pipes_pids(t_pipex *data, int size);
void	ft_error(char *str);
void	open_src(char **argv, t_pipex *data);
void	open_dest(char *path, t_pipex *data);
void	ex_err(char *str);
void	init_pipe(t_pipex *data);
void	init(t_pipex *data);
void	check_cmd(char *cmd, char **env);
void	ft_putendl_fd(char *s, int fd);
void	free_split(char **strs);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**get_args(char *cmd);
int		check_args(int argc, char **argv, t_pipex *data);
int		has_heredoc(char *first_arg);
int		check_access(char **paths_splited, char *cmd, char **env);
int		check_path(char *path, char *cmd, char **env);
int		find_path(char **env, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_message(char *paths, char **paths_splited, char *cmd);
#endif
