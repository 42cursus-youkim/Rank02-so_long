/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:50:57 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 13:33:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ymemset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (--len > 0)
		ptr[len] = c;
	return (b);
}

void	ybzero(void *s, size_t n)
{
	ymemset(s, 0, n);
}

void	*ycalloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr)
		ybzero(ptr, size * count);
	return (ptr);
}
