/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:29:52 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 20:11:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	log at STDOUT, but does not kill process
void	ywarn(char *warn)
{
	char	*msg;

	msg = new_ystrjoin((char *[]) \
		{"[Warning]\n    ", warn, "\n", NULL} \
	);
	ywritecolor(1, msg, YEL);
	del_ystr(msg);
}

//	log at STDERR, kill process
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

int	ycheckerr(int statement, char *err)
{
	if (statement == ERROR)
		yerror("ycheckerr", err);
	return (statement);
}
