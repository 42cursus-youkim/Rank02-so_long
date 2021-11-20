/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:20:55 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 19:49:13 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//length of a string. null termination is not counted.
int	ystrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// compare two null-terminated strings. returns non-zero if they differ
int	ystrcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
