/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:33 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/20 12:08:52 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*select_path(char **paths, char *cmd);

char	*pathfinder(char **envp, char *cmd)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
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
			return (free_matrix(paths));
		pathfull = ft_strjoin(pathsl, cmd);
		free(pathsl);
		if (!pathfull)
			return (free_matrix(paths));
		if (access(pathfull, F_OK) == 0)
		{
			free_matrix(paths);
			return (pathfull);
		}
	}
	free(pathfull);
	free_matrix(paths);
	return (NULL);
}

char	*free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (matrix == NULL)
		return (NULL);
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	return (NULL);
}


