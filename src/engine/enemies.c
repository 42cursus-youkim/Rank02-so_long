/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:23:06 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 14:07:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_there_enemy(t_map *map, t_vec *pos)
{
	int	id;

	id = -1;
	while (map->enemylst[++id])
		if (pos->x == map->enemylst[id]->x && pos->y == map->enemylst[id]->y)
			return (true);
	return (false);
}

void	del_enemies(t_vec **enemylst)
{
	int	i;

	i = -1;
	while (enemylst[++i])
		free(enemylst[i]);
	free(enemylst);
}

void	init_enemies(t_map *map)
{
	int	i;

	i = -1;
	map->enemylst = malloc((map->disks + 1) * sizeof(t_vec *));
	if (!map->enemylst)
		yerror("init_enemies", "could not malloc!");
	map->enemylst[map->disks] = NULL;
	while (++i < (int)map->disks)
	{
		map->enemylst[i] = malloc(sizeof(t_vec));
		if (!map->enemylst[i])
			yerror("init_enemies", "could not malloc element!");
		vec_set(map->enemylst[i], 0, 0);
	}
}
