/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:46:37 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 18:40:33 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	visualize list. only works when EVERY values are string.
void	ydict_list_items(t_dict *dict)
{
	size_t		id;
	t_dictitem	*item;

	id = 0;
	printf("%sID |%-8s|%-12s%s\n", UMAG, "KEY", "VALUE", END);
	while (id < dict->capacity)
	{
		item = dict->items[id];
		if (item && item->key)
			printf("%s%2zu |%-8s|%s\n%s",
				HGRN, id++, item->key, item->value, END);
		else
			printf("%2zu |%8s|\n", id++, "");
	}
}
