/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:16 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 11:40:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_input_valid(t_dict *dict, char *key, void *value)
{
	if (!dict || !key || !value)
		yerror("is_input_valid", "invalid argument");
	if (dict->size == dict->capacity)
	{
		ywarn("is_input_valid", "dict is full");
		return (false);
	}
	return (true);
}

bool	is_key_vacant(t_dict *dict, int id)
{
	return (!dict->items[id]);
}

bool	is_key_update(t_dict *dict, int id, char *key)
{
	return (ystrcmp(dict->items[id]->key, key) == NODIFF);
}
