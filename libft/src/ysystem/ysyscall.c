/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysyscall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:40:48 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 12:37:39 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	just an wrapper for write() but without annoying length parameter
int	ywrite(int fd, char *str)
{
	return (write(fd, str, ystrlen(str)));
}

//	same as write but with colors
int	ywritecolor(int fd, char *str, char *color)
{
	int		result;
	char	*temp;

	temp = new_ystr(str);
	ystr_color(&temp, color);
	result = ywrite(fd, temp);
	del_ystr(temp);
	return (result);
}

/*	similar to read but NULL-terminates the string. returns sizes read.
	string size should be at least 1 bigger than the buffer_size.
*/
int	yread(int fd, char *buf, int buffer_size)
{
	int	len;

	len = read(fd, buf, buffer_size);
	if (len == ERROR)
		return (ERROR);
	buf[len] = '\0';
	return (len);
}

// TODO: ymemcpy
// void	*ymemcpy(void *dest, const void *src, size_t count)
// {

// }
