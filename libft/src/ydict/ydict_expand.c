/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:18:19 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 18:02:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_newkey_vacant(t_dictitem **new_items, int id)
{
	return (!new_items[id]);
}

static void	ydict_moveprobeditem(
	t_dictitem **new_items, int id, t_dictitem *item
)
{
	new_items[id] = item;
}

static void	ydict_probenew(
	t_dictitem **new_items, int new_capacity, int id, t_dictitem *item
)
{
	int	i;

	i = id;
	while (++i < new_capacity)
		if (is_newkey_vacant(new_items, i))
			return (ydict_moveprobeditem(new_items, i, item));
	i = -1;
	while (++i < id)
		if (is_newkey_vacant(new_items, i))
			return (ydict_moveprobeditem(new_items, i, item));
	ywarn("could not move item to new array due to NO SPACE LEFT in new array");
}

static void	ydict_move_items(
	t_dict *dict, t_dictitem **new_items, int new_capacity
)
{
	int			i;
	int			id;
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

//	creates new dictitems, and moves all items to new array with new hash ids
int	ydict_expand(t_dict *dict)
{
	int			new_capacity;
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
