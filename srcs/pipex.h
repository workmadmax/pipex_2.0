/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:13:26 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:41 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void	child_proc(int filein, char **argv, char **envp, int *fd);
void	exec_proc(char *argv, char **envp);
void	parent_proc(int fileout, char **argv, char **envp, int *fd);
void	pipex(int filein, int fileout, char **argv, char **evnp);

/* paths_utils */

char	*find_path(char *ptr, char *cmd);
char	*get_path(char **envp);
void	format_cmd(char **str, int value, int sub);
void	cmd_format(char **cmd);

/* handle error */

void	free_mtx(char **matrix);
void	error_filein(char **argv, int filein);
void	cmd_not_found(int run, char **cmd);

#endif