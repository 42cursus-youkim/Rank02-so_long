/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:23:42 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 12:24:53 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// creates a new dictonary item, with key and value
t_dictitem	*new_ydictitem(const char *key, const char *value)
{
	t_dictitem	*item;

	item = malloc(sizeof(t_dictitem));
	if (!item)
		return (NULL);
	item->key = new_ystr(key);
	item->value = new_ystr(value);
	return (item);
}

//	creates new NULL-set array of items
t_dictitem	**new_ydictitem_arr(size_t capacity)
{
	size_t		id;
	t_dictitem	**items;

	items = ycalloc(capacity, sizeof(t_dictitem *));
	if (!items)
		return (NULL);
	id = 0;
	while (id < capacity)
		items[id++] = NULL;
	return (items);
}

//	initializes dictionary and NULLs items
static void	ydict_init(t_dict *dict)
{
	dict->size = 0;
	dict->capacity = YDICT_INITIAL_CAPACITY;
	dict->items = new_ydictitem_arr(dict->capacity);
}

// creates an empty dict. returns NULL if memory allocation fails.
t_dict	*new_ydict(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	ydict_init(dict);
	if (dict->items)
		return (dict);
	else
	{
		free(dict->items);
		free(dict);
		return (NULL);
	}
}
