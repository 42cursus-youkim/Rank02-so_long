/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 12:21:51 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#undef YDICT_INITIAL_CAPACITY
#define YDICT_INITIAL_CAPACITY 16

//	insert new item at empty index of dictionary
void	ydict_insert(t_dict *dict, int id, char *key, char *value)
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
	int	id;

	if (!is_input_valid(dict, key, value))
		yerror("ydict_set", "invalid input");
	id = ydict_getid(dict, key);
	if (is_dict_almostfull(dict))
		ydict_expand(dict);
	if (is_key_vacant(dict, id))
		ydict_insert(dict, id, key, value);
	else if (is_key_update(dict, id, key))
		ydict_update(dict, id, value);
	printf("ydict_set:id: %d | capacity %zu/%zu\n", id,
		dict->size, dict->capacity);
}
