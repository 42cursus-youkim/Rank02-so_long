/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysyscall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:40:48 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:57:28 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// just an wrapper for write() but without annoying length parameter
int	ywrite(int fd, char *str)
{
	return (write(fd, str, ystrlen(str)));
}
