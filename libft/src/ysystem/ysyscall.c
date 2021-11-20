/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysyscall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:40:48 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 18:15:49 by youkim           ###   ########.fr       */
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
