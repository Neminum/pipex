/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/04/03 17:26:09 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <wait.h>

int		main(int argc, char **argv, char **envp);
char	*pathfinder(char **envp, char *cmd);
void	execute(char *argv, char **envp);
void	child(char *argv, char **envp);
void	exit_free(char *str);
int		get_line(char **line);
void	error(void);

#endif
