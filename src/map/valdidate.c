/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valdidate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:41:36 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 19:45:30 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_checklist(t_checklist *checklist, t_vec *vec)
{
	vec_set(vec, -1, -1);
	checklist->is_wall_valid = true;
	checklist->has_exit = false;
	checklist->has_player = false;
	checklist->has_collectible = false;
}

int	valdidate_map_file(t_map *map)
{
	t_vec		vec;
	t_checklist	checklist;

	init_checklist(&checklist, &vec);
	while (++vec.y < map->size.h)
	{
		vec.x = -1;
		while (++vec.x < map->size.w)
		{
			if (map->grid[vec.y][vec.x] == 'P')
			{
				checklist.has_player = true;
				vec_assign(&map->ppos, &vec);
			}
			if (map->grid[vec.y][vec.x] == 'E')
				checklist.has_exit = true;
			if (map->grid[vec.y][vec.x] == 'C')
				checklist.has_collectible = true;
		}
	}
}
