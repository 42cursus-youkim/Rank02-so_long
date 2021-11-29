/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:51:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 19:56:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ylistlen(t_list *lst)
{
	int		len;

	len = 0;
	while (lst && len++ >= 0)
		lst = lst->next;
	return (len);
}

t_list	*ylistindex(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst && i++ < index)
		lst = lst->next;
	return (lst);
}
