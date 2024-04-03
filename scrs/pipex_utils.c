/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:33 by tsurma            #+#    #+#             */
/*   Updated: 2024/04/03 18:24:29 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*select_path(char **paths, char *cmd);

char	*pathfinder(char **envp, char *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		error();
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		error();
	return (select_path(paths, cmd));
}

static char	*select_path(char **paths, char *cmd)
{
	char	*pathsl;
	char	*pathfull;
	int		i;

	i = -1;
	while (paths[++i])
	{
		pathsl = ft_strjoin(paths[i], "/");
		if (!pathsl)
			return (ft_free_matrix(paths));
		pathfull = ft_strjoin(pathsl, cmd);
		free(pathsl);
		if (!pathfull)
			return (ft_free_matrix(paths));
		if (access(pathfull, F_OK) == 0)
		{
			ft_free_matrix(paths);
			return (pathfull);
		}
		free(pathfull);
	}
	ft_free_matrix(paths);
	return (NULL);
}

void	exit_free(char *str)
{
	if (!str)
		error();
	free(str);
	error();
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error();
	path = pathfinder(envp, cmd[0]);
	if (!path)
	{
		ft_free_matrix(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_matrix(cmd);
		free(path);
		error();
	}
	if (path)
		free(path);
}
