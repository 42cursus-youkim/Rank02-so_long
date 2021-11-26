/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:45:52 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 11:48:30 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_ydictitem(t_dict *dict, int id)
{
	t_dictitem	*item;

	item = dict->items[id];
	del_ystr(item->key);
	dict->del_value(item->value);
	free(item);
}

//	uses internal function pointer as destructor.
void	del_ydict(t_dict *dict)
{
	int	i;

	if (!dict)
		yerror("del_ydict", "tried to free nonexsistant ydict struct");
	i = -1;
	while (++i < (int)dict->capacity)
		if (dict->items[i])
			del_ydictitem(dict, i);
	free(dict->items);
	free(dict);
}
