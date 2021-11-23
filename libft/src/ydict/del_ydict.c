/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:45:52 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 18:59:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_ydictitem(t_dictitem *item, void (*del_value)(void *))
{
	del_ystr(item->key);
	del_value(item->value);
	free(item);
}

//	uses function pointer as destructor.
void	del_ydictff(t_dict *dict, void (*del_value)(void *))
{
	int	i;

	if (!dict)
		yerror("del_ydict", "tried to free nonexsistant ydict struct");
	i = -1;
	while (++i < (int)dict->capacity)
		if (dict->items[i])
			del_ydictitem(dict->items[i], del_value);
	free(dict->items);
	free(dict);
}

//	for simple values that does not require destructor.
void	del_ydict(t_dict *dict)
{
	del_ydictff(dict, free);
}
