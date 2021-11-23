/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:16 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 15:35:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_input_valid(t_dict *dict, char *key, void *value)
{
	return (dict && key && value);
}

bool	is_key_vacant(t_dict *dict, int id)
{
	return (!dict->items[id]);
}

bool	is_key_update(t_dict *dict, int id, char *key)
{
	return (ystrcmp(dict->items[id]->key, key) == NODIFF);
}

bool	is_dict_almostfull(t_dict *dict)
{
	printf("%zu %zu\n", dict->size, dict->capacity / 2);
	return (dict->size >= dict->capacity / 2);
}
