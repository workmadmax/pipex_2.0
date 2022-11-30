/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:55:44 by mdouglas          #+#    #+#             */
/*   Updated: 2022/11/30 11:09:30 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <string.h>

void    parent_process(int fileout, char **argv, char **envp, int *fd);
void    child_process(int filein, char **argv, char **evnp, int *fd);
void    pipex(int filein, int fileout, char **argv, char **envp);
void    exec(char *argv, char **envp);
void    free_tab(char **tab);
char    *find_path(char  *p, char *cmd);
char    *get_path(char **envp);

#endif