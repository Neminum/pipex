/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:55:40 by tsurma            #+#    #+#             */
/*   Updated: 2024/04/03 16:55:53 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_line(char **line)
{
	char	*buf;
	int		ret;
	int		i;
	char	c;

	i = 0;
	ret = 0;
	buf = ft_calloc(sizeof(char), 5000);
	if (!buf)
		return (-1);
	ret = read(0, &c, 1);
	if (ret == -1)
		error();
	while (ret && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buf[i] = c;
		++i;
		ret = read(0, &c, 1);
	}
	buf[i] = '\n';
	buf[++i] = '\0';
	*line = buf;
	return (ret);
}
