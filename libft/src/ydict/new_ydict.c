/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:23:42 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 19:25:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// initializes dictionary and NULLs items
static void	ydict_init(t_dict *dict)
{
	int	i;

	dict->size = 0;
	dict->capacity = YDICT_INITIAL_CAPACITY;
	dict->items = ycalloc(dict->capacity, sizeof(t_dictitem *));
	i = -1;
	while (++i < (int)dict->capacity)
		dict->items[i] = NULL;
}

// creates an empty dict. returns NULL if memory allocation fails.
t_dict	*new_ydict(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	ydict_init(dict);
	if (dict->items)
		return (dict);
	else
	{
		free(dict->items);
		free(dict);
		return (NULL);
	}
}
