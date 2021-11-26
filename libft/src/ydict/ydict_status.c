/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:16 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 11:28:41 by youkim           ###   ########.fr       */
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
	return (ystrequ(dict->items[id]->key, key));
}

bool	is_dict_almostfull(t_dict *dict)
{
	return (dict->size >= dict->capacity / 2);
}

bool	is_capacity_overflow(t_dict *dict)
{
	int	new_capacity;

	new_capacity = dict->capacity * 2;
	return (new_capacity < dict->capacity);
}
