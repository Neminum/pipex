/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:27:51 by tsurma            #+#    #+#             */
/*   Updated: 2024/04/05 16:15:07 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	open_file(char *file, int indicator);

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		error();
	i = 2;
	outfile = open_file(argv[argc - 1], 0);
	infile = open_file(argv[1], 2);
	dup2(infile, STDIN_FILENO);
	while (i < argc - 2)
		child(argv[i++], envp);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (0);
}

static int	open_file(char *file, int indicator)
{
	int	ret;

	if (indicator == 0)
		ret = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		ret = open(file, O_RDONLY, 0777);
	if (ret < 0)
		error();
	return (ret);
}

void	child(char *argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
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


