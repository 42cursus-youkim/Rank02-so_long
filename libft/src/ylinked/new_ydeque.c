/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ydeque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:47:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 12:30:46 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dequenode	*new_ydequenode(int num)
{
	t_dequenode	*node;

	node = malloc(sizeof(t_dequenode));
	if (!node)
		return (NULL);
	node->num = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_deque	*new_ydeque(int size, int nums[])
{
	return (NULL);
}
