/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:54:05 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 16:29:38 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	same as free. hmmm....
void	del_ystr(char *str)
{
	free(str);
}

//	usage: del_ystr((char *[]){str, ..., NULL});
void	del_ystrs(char *strs[])
{
	int	i;

	i = -1;
	while (strs[++i])
		del_ystr(strs[i]);
}
