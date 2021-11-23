/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 11:50:13 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	insert new item at empty index of dictionary
static void	ydict_insert(t_dict *dict, int id, char *key, char *value)
{
	t_dictitem	*item;

	item = new_ydictitem(key, value);
	dict->items[id] = item;
	dict->size++;
}

//	replace the value of an existing key
static void	ydict_update(t_dict *dict, int id, char *value)
{
	free(dict->items[id]->value);
	dict->items[id]->value = new_ystr(value);
}

void	ydict_set(t_dict *dict, char *key, char *value)
{
	int			id;

	if (!is_input_valid(dict, key, value))
		return ;
	id = ydict_getid(dict, key);
	printf("ydict_set:id: %d | capacity %zu/%zu\n", id,
		dict->size, dict->capacity);
	if (is_key_vacant(dict, id))
		ydict_insert(dict, id, key, value);
	else if (is_key_update(dict, id, key))
		ydict_update(dict, id, value);
	else
	{
		ywarn("ydict_set", "hash collision");
		ydict_expand(dict);
	}
}
