/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:59:51 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:20 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parent_proc(int fileout, char **argv, char **envp, int *fd)
{
    dup2(fd[0], STDIN_FILENO);
    dup2(fileout, STDOUT_FILENO);
    close(fd[1]);
    exec_proc(argv[3], envp);
}
