/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:16:26 by mdouglas          #+#    #+#             */
/*   Updated: 2022/11/30 10:34:34 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec(char *argv, char **envp)
{
    char    **cmd;
    char    **full_path;
    char    *path;
    int     i;
    int     run;

    full_path = ft_split(get_path(envp), ':');
    cmd = ft_split(argv, ' ');
    i = 0;
    run = 0;
    while (full_path[i])
    {
        path = find_path(ft_strjoin(full_path[i], "/"), cmd[0]);
        if (execve(path, cmd, envp) == 0)
            run = 1;
        free(path);
        i++;
    }
    free_tab(full_path);
    free_tab(cmd);
    if (run == 0)
    {
        perror("Error nos comandos passados");
        exit(EXIT_FAILURE);
    }
}
