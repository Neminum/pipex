/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:54:28 by tsurma            #+#    #+#             */
/*   Updated: 2024/04/03 18:24:36 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	open_file(char *file, int indicator);
static void	here_doc(char *delim);

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6))
		error();
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		++i;
		outfile = open_file(argv[argc - 1], 1);
		here_doc(argv[2]);
	}
	else
	{
		outfile = open_file(argv[argc - 1], 0);
		infile = open_file(argv[1], 2);
		dup2(infile, STDIN_FILENO);
	}
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
	else if (indicator == 1)
		ret = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		ret = open(file, O_RDONLY, 0444);
	if (!ret)
		error();
	return (ret);
}

static void	here_doc(char *delim)
{
	int		fd[2];
	char	*line;
	pid_t	pid;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
				exit_free(line);
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
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
