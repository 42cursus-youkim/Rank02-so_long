/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:24:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 11:33:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	yexit(int status)
{
	exit(status);
}

void	yerror(char *where, char *err)
{
	char	*msg;

	msg = new_ystrjoin((char *[]) \
		{"[Error! @ ", where, "]\n    ", err, "\n", NULL} \
	);
	ywritecolor(2, msg, BHRED);
	del_ystr(msg);
	yexit(1);
}
