/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:20:43 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:34 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int filein, int fileout, char **argv, char **envp)
{
	int	fd[2];
	int	parent;

	if (pipe(fd) == -1)
	{
		perror("failed pipe");
		exit(EXIT_FAILURE);
	}
	parent = fork();
	if (parent == -1)
	{
		perror("failed fork");
		exit(EXIT_FAILURE);
	}
	if (parent == 0)
		child_proc(filein, argv, envp, fd);
	else
	{
		waitpid(parent, NULL, WNOHANG);
		parent_proc(fileout, argv, envp, fd);
	}
}
