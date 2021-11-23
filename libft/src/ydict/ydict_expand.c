/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:18:19 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 17:26:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_newkey_vacant(t_dictitem **new_items, size_t id)
{
	return (!new_items[id]);
}

static void	ydict_moveprobeditem(
	t_dictitem **new_items, size_t id, t_dictitem *item
)
{
	new_items[id] = item;
}

static void	ydict_probenew(
	t_dictitem **new_items, size_t new_capacity, size_t id, t_dictitem *item
)
{
	size_t	i;

	i = id;
	while (++i < new_capacity)
		if (is_newkey_vacant(new_items, i))
			return (ydict_moveprobeditem(new_items, i, item));
	i = 0;
	while (i < id)
		if (is_newkey_vacant(new_items, ++i))
			return (ydict_moveprobeditem(new_items, --i, item));
	ywarn("for some mysterious reason new dict is FULL! how come???");
}

static void	ydict_move_items(
	t_dict *dict, t_dictitem **new_items, int new_capacity
)
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
			if (is_newkey_vacant(new_items, id))
				new_items[id] = item;
			else
				ydict_probenew(new_items, new_capacity, id, item);
		}
		i++;
	}
	free(dict->items);
	dict->items = new_items;
}

//	returns
int	ydict_expand(t_dict *dict)
{
	size_t		new_capacity;
	t_dictitem	**new_items;

	if (is_capacity_overflow(dict))
		return (ERROR);
	new_capacity = dict->capacity * 2;
	new_items = new_ydictitem_arr(new_capacity);
	if (!new_items)
		return (ERROR);
	ydict_move_items(dict, new_items, new_capacity);
	dict->capacity = new_capacity;
	return (SUCCESS);
}
