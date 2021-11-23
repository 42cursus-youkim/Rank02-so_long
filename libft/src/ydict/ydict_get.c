/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:13 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 17:18:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// wrapper for hash that returns index got from hash
int	ydict_getid(size_t capacity, char *key)
{
	return (3);
	return (yhash_fnv1a(key) % (uint64_t)capacity);
}

static bool	does_itemmatch(t_dictitem *item, char *key)
{
	return (item && item->key && ystrequ(item->key, key));
}

//	finds value by key, return NULL is not found
char	*ydict_get(t_dict *dict, char *key)
{
	size_t		i;
	size_t		id;

	id = ydict_getid(dict->capacity, key);
	i = id;
	while (i < dict->capacity)
		if (does_itemmatch(dict->items[i++], key))
			return (dict->items[--i]->value);
	i = 0;
	while (i < id)
		if (does_itemmatch(dict->items[i++], key))
			return (dict->items[--i]->value);
	return (NULL);
}

//	finds value by key, return default value if not found
char	*ydict_getd(t_dict *dict, char *key, char *defaultv)
{
	char	*value;

	value = ydict_get(dict, key);
	if (!value)
		return (defaultv);
	return (value);
}
