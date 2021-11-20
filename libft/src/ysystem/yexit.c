/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:24:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:55:16 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	yexit(int status)
{
	exit(status);
}

void	yerror(char *err)
{
	char	*msg;

	msg = new_ystrjoin((char *[]) \
		{"[Error!]\n    ", err, "\n", NULL} \
	);
	ystr_color(&msg, RED);
	ywrite(2, msg);
	del_ystr(msg);
	yexit(1);
}
