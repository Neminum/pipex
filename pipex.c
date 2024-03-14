/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:27:51 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/14 18:29:14 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		return (0);
	i = 2;
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[--argc], O_WRONLY);
	if (infile == -1 || outfile == -1)
		return (0);
	if (dup2(infile, STDIN_FILENO) == -1)
		return (0);
	fork(argv[++i], envp);

	return (0);
}

void	fork(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];
}

char	*pathfinder(char **envp, char *cmd)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	i = -1;
	while (paths[++i] != NULL)
	{
		temp = ft_strjoin(paths[i], '/');
		temp2 = ft_strjoin(temp, cmd);
		free(temp);
		if (access(temp2, F_OK) == 0)
		{
			free_matrix(paths);
			return()
		}
	}

}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (matrix == NULL)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
