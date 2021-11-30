/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:23:42 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 20:15:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	creates a new dictonary item, with key and value
t_dictitem	*new_ydictitem(const char *key, void *value)
{
	t_dictitem	*item;

	item = malloc(sizeof(t_dictitem));
	if (!item)
		return (NULL);
	item->key = new_ystr(key);
	item->value = value;
	return (item);
}

//	creates new NULL-set array of items
t_dictitem	**new_ydictitem_arr(int capacity)
{
	int			id;
	t_dictitem	**items;

	items = ycalloc(capacity, sizeof(t_dictitem *));
	if (!items)
		return (NULL);
	id = -1;
	while (++id < capacity)
		items[id] = NULL;
	return (items);
}

//	initializes dictionary, NULLs items, saves
static void	ydict_setup(t_dict *dict, t_destructor_f del_value)
{
	dict->size = 0;
	dict->capacity = YDICT_INITIAL_CAPACITY;
	dict->items = new_ydictitem_arr(dict->capacity);
	dict->del_value = del_value;
}

/*	creates an empty dict with destructor.
	Internal structure assumes all items are of SAME TYPE.
	(or, it should be able to deconstructed with same del_func pointer)
	returns NULL if memory allocation fails.
*/
t_dict	*new_ydict(t_destructor_f del_value)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	ydict_setup(dict, del_value);
	if (dict->items)
		return (dict);
	else
	{
		free(dict->items);
		free(dict);
		return (NULL);
	}
}

//	creates a new dict with string k,v
t_dict	*new_ydictinits(t_destructor_f del_value, char *key[], char *value[])
{
	int		i;
	t_dict	*dict;

	dict = new_ydict(del_value);
	if (!dict)
		return (NULL);
	i = -1;
	while (key[++i] && value[i])
		ydict_setstr(dict, key[i], value[i]);
	return (dict);
}
