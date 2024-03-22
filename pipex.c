/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:27:51 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/20 12:07:04 by tsurma           ###   ########.fr       */
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
	i = 1;
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (infile == -1 || outfile == -1)
		return (0);
	dup2(infile, STDIN_FILENO);
	while (++i < argc - 2)
		child(argv[i], envp);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (0);
}

void	child(char *argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	execute(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		return ;
	path = pathfinder(envp, cmd[0]);
	if (!path)
	{
		free_matrix(cmd);
		return ;
	}
	if (execve(path, cmd, envp) == -1)
		return ;
}
