/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:46 by tsurma            #+#    #+#             */
/*   Updated: 2023/12/13 19:28:17 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*returns(t_all_I_need *a)
{
	a->len = 0;
	free(a->buf);
	if (a->last != NULL)
		free(a->last);
	a->last = NULL;
	return (a->last);
}

char	*returns1(t_all_I_need *a)
{
	a->len = 0;
	free(a->buf);
	a->buf = a->last;
	a->last = NULL;
	return (a->buf);
}

char	*returns2(t_all_I_need *a)
{
	a->len = 0;
	free(a->last);
	a->last = NULL;
	return (a->buf);
}
