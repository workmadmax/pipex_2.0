/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:06:32 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/03 11:18:38 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int filein;
    int fileout;
    
    if (argc == 5)
    {
        filein = open(argv[1], O_RDONLY);
        if (filein == -1)
        {
            perror("");
            exit(EXIT_FAILURE);
        }
        fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (fileout == -1)
        {
            perror("");
            exit(EXIT_FAILURE);
        }
        pipex(filein, fileout, argv, envp);
    }
    else
    {
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    return (0);
}
