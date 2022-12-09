/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:28:26 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:29:57 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_proc(char *argv, char **envp)
{
	int		idx;
	int		run;
	char	**cmd;
	char	*path;
	char	**full_path;

	full_path = ft_split(get_path(envp), ':');
	format_cmd(&argv, 32, 1);
	cmd = ft_split(argv, ' ');
	cmd_format(cmd);
	idx = 0;
	run = 0;
	while (full_path[idx])
	{
		path = find_path(ft_strjoin(full_path[idx], "/"), cmd[0]);
		if (execve(path, cmd, envp) == 0)
			run = 1;
		free(path);
		idx++;
	}
	free_mtx(full_path);
	if (run == 0)
		cmd_not_found(run, &cmd[0]);
	free_mtx(cmd);
}
