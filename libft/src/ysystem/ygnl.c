/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ygnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:37 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 12:59:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns A LINE of TEXT from File Discriptor
char	*ygnl(int fd)
{
	int		read_size;
	char	*buf;
	char	*str;

	buf = new_ystrm(BUFFER_SIZE + 1);
	str = new_ystrm(0);
	if (!buf || !str)
		return (NULL);
	while (true)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		printf("[%s]:%d\n", buf, ystrchri(buf, '\n'));
		if (read_size <= 0)
			break ;
	}
	return (buf);
}
