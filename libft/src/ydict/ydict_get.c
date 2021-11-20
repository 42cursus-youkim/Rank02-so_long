/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:13 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 21:24:42 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ydict_get(t_dict *dict, char *key)
{
	int			id;
	t_dictitem	*item;

	id = yhash_fnv1a(key) % (uint64_t)dict->capacity;
	item = dict->items[id];
	if (!item || ystrcmp (item->key, key) != 0)
		return (NULL);
	return (item->value);
}
