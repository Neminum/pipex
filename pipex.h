/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/13 18:44:30 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_all
{
	int		infile;
	int		outfile;
	int		stdoutb;
	int		stdinb;
	int		i;
	char	**args;
}	t_all;

// typedef enum
// {
// 	NOFILE = "No such file in Directory";
// 	FILESERR
// }	t_err;

int		main(int argc, char **argv);


#endif
