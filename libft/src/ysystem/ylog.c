/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:29:52 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 13:33:26 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	log at STDERR, but does not kill process
void	ywarn(char *where, char *warn)
{
	char	*msg;

	msg = new_ystrjoin((char *[]) \
		{"[Warning @", where, "]\n    ", warn, "\n", NULL} \
	);
	ywritecolor(2, msg, YEL);
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
