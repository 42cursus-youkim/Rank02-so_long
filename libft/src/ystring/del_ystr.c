/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:54:05 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 11:36:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	same as free, but can be used for ff. please ONLY put char * here.
void	del_ystr(void *str)
{
	free((char *)str);
}

//	usage: del_ystr((char *[]){str, ..., NULL});
void	del_ystrs(char *strs[])
{
	int	i;

	i = -1;
	while (strs[++i])
		del_ystr(strs[i]);
}
