/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:23:06 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:37:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemies(t_map *map)
{
	int	i;

	i = -1;
	map->enemylst = malloc((map->disks + 1) * sizeof(t_vec *));
	if (!map->enemylst)
		yerror("init_enemies", "could not malloc!");
	while (++i < (int)map->disks)
	{
		map->enemylst[i] = malloc(sizeof(t_vec));
		if (!map->enemylst[i])
			yerror("init_enemies", "could not malloc element!");
		vec_set(map->enemylst[i], 0, 0);
	}
}
