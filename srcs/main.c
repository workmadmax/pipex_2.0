/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:13:10 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:10 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	filein;
	int	fileout;

	if (argc == 5)
	{
		fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fileout == -1)
		{
			perror("failed fileout");
			exit(EXIT_FAILURE);
		}
		filein = open(argv[1], O_RDONLY);
		if (filein == -1)
			error_filein(&argv[1], filein);
		pipex(filein, fileout, argv, envp);
	}
	else
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	return (0);
}
