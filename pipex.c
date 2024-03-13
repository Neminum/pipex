/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:27:51 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/13 18:52:12 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	 static t_all	a;

	argc--;
	a.infile = open(argv[1], O_RDONLY);
	a.outfile = open("outfile", O_WRONLY);
	if (a.infile == -1 || a.outfile == -1)
		exit (0);
	if (dup2(STDOUT_FILENO, a.stdoutb) == -1
		|| dup2(a.outfile, STDOUT_FILENO) == -1)
		exit (1);
	if (dup2(STDIN_FILENO, a.stdinb) == -1
		|| dup2(a.infile, STDIN_FILENO) == -1)
		exit (2);
	a.i = 1;
	char *cmd = "/bin/sh"; // or the path to your shell
	char *args[] = {cmd, "-c", argv[2], NULL};
	execv(cmd, args);
	return (0);
}
