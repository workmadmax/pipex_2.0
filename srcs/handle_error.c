/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:08:44 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/06 21:57:00 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(int n, char **cmd)
{
	if (n == 0)
	{
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": Command not found\n", 20);
		free_mtx(cmd);
		exit(127);
	}
}

void	error_filein(char **argv, int filein)
{
	if (filein == -1)
	{
		perror(argv[1]);
		exit (0);
	}
}

void	free_mtx(char **matrix)
{
	int	idx;

	idx = 0;
	while (matrix[idx])
		free(matrix[idx++]);
	free(matrix);
}