/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:18:19 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 15:53:28 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_capacity_overflow(int new, int old)
{
	return (new < old);
}

static void	ydict_move_items(
	t_dict *dict, t_dictitem **new_items, int new_capacity)
{
	size_t		i;
	size_t		id;
	t_dictitem	*item;

	i = 0;
	while (i < dict->capacity)
	{
		item = dict->items[i];
		if (item && item->key)
		{
			id = ydict_getid(new_capacity, item->key);
			new_items[id] = item;
		}
		i++;
	}
	free(dict->items);
	dict->items = new_items;
}

bool	ydict_expand(t_dict *dict)
{
	size_t		new_capacity;
	t_dictitem	**new_items;

	new_capacity = dict->capacity * 2;
	if (is_capacity_overflow(new_capacity, dict->capacity))
		return (false);
	new_items = new_ydictitem_arr(new_capacity);
	if (!new_items)
		return (false);
	ydict_move_items(dict, new_items, new_capacity);
	dict->capacity = new_capacity;
	return (true);
}
