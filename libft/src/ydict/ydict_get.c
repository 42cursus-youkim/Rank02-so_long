/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:13 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 16:18:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// wrapper for hash that returns index got from hash
int	ydict_getid(size_t capacity, char *key)
{
	return (yhash_fnv1a(key) % (uint64_t)capacity);
}

//	finds value by key, return NULL is not found
char	*ydict_get(t_dict *dict, char *key)
{
	int			id;
	t_dictitem	*item;

	id = ydict_getid(dict->capacity, key);
	printf("id: %d\n", id);
	item = dict->items[id];
	if (!item || ystrcmp (item->key, key) != NODIFF)
		return (NULL);
	return (item->value);
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
