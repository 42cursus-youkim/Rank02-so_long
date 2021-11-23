/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:18:19 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 12:14:29 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_capacity_overflow(int new, int old)
{
	return (new < old);
}

bool	ydict_expand(t_dict *dict)
{
	size_t		new_capacity;
	t_dictitem	**new_items;

	new_capacity = dict->capacity * 2;
	if (is_capacity_overflow(new_capacity, dict->capacity))
		return (false);
	new_items = ycalloc(new_capacity, sizeof(t_dictitem *));
	ywarn("ydict_expand", "will resolve hash collision");
	if (dict)
		return (true);
	return (true);
}
