/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 21:25:23 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid(t_dict *dict, char *key, void *value)
{
	if (!dict || !key || !value)
		yerror("ydict_set: invalid argument");
	if (dict->size == dict->capacity)
	{
		ywritecolor(2, "ydict_set: dict is full\n", RED);
		return (false);
	}
	return (true);
}

static bool	is_key_vacant(t_dict *dict, int id)
{
	return (!dict->items[id]);
}

static bool	is_key_update(t_dict *dict, int id, char *key)
{
	return (ystrcmp(dict->items[id]->key, key) != 0);
}

void	ydict_set(t_dict *dict, char *key, char *value)
{
	int			id;
	t_dictitem	*item;

	if (!is_valid(dict, key, value))
		return ;
	id = yhash_fnv1a(key) % (uint64_t)dict->capacity;
	item = new_ydictitem(key, value);
	if (is_key_vacant(dict, id))
	{
		dict->items[id] = item;
		dict->size++;
	}
	else if (is_key_update(dict, id, key))
	{
		free(dict->items[id]->value);
		dict->items[id]->value = new_ystr(value);
	}
	// else
		// ydict_handlecollision(dict, item);
}
