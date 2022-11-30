/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:02:08 by mdouglas          #+#    #+#             */
/*   Updated: 2022/11/30 10:06:12 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int filein, int fileout, char **argv, char **envp)
{
    int fd[2];
    int parent;

    if (pipe(fd) == -1)
    {
        perror("Falha no pipe");
        exit(EXIT_FAILURE);
    }
    parent = fork();
    if (parent == -1)
    {
        perror("Fork falhou");
        exit(EXIT_FAILURE);
    }
    if (parent == 0)
        child_process(filein, argv, envp, fd);
    else
    {
        waitpid(parent, NULL, 0);
        parent_process(fileout, argv, envp, fd);
    }
}
