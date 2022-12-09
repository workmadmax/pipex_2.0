/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:35:54 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/09 10:31:28 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_format(char **cmd)
{
	int		idx;
	char	*tmp;

	idx = 0;
	while (cmd[idx])
	{
		format_cmd(&cmd[idx], 1, 32);
		tmp = cmd[idx];
		cmd[idx] = ft_strtrim(cmd[idx], "'");
		idx++;
		free(tmp);
	}
}

void	format_cmd(char **str, int value, int sub)
{
	int		idx;
	int		asp;
	char	*tmp;

	tmp = *str;
	asp = 0;
	idx = -1;
	while (tmp[++idx])
	{
		if (tmp[idx] == 39)
			asp++;
		if (asp % 2 == 1 && tmp[idx] == value)
			tmp[idx] = sub;
	}
	tmp = NULL;
}

char	*find_path(char *ptr, char *cmd)
{
	char	*path;

	path = ft_strjoin(ptr, cmd);
	free(ptr);
	return (path);
}

char	*get_path(char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], "PATH=", 5) == 0)
			return (envp[idx] + 5);
		idx++;
	}
	return (NULL);
}
