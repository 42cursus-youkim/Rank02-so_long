/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valdidate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:41:36 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 10:23:40 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	set_map_size_and_is_valid(t_map *map)
{
	int		len;
	int		prev;
	t_vec	vec;

	prev = 0;
	vec_set(&vec, -1, -1);
	while (map->grid[++vec.y])
	{
		len = 0;
		vec.x = -1;
		while (map->grid[vec.y][++vec.x])
			++len;
		if (prev && prev != len)
			return (false);
		prev = len;
	}
	size_set(&map->size, vec.x, vec.y);
	return (true);
}

static void	init_checklist(t_checklist *chk, t_vec *vec, t_map *map)
{
	vec_set(vec, -1, -1);
	chk->is_wall_valid = true;
	chk->has_exit = false;
	chk->has_player = false;
	map->disks = 0;
}

static void	check_map(t_map *map, t_vec *vec, t_checklist *chk)
{
	char	entity;

	entity = map->grid[vec->y][vec->x];
	if ((vec->y == 0 || vec->y == map->size.h - 1 \
		|| vec->x == 0 || vec->x == map->size.w - 1) \
		&& entity != WALL)
		chk->is_wall_valid = false;
	if (entity == PLAYER)
	{
		chk->has_player = true;
		vec_assign(&map->ppos, vec);
	}
	if (entity == DISK)
		map->disks++;
	if (entity == EXIT)
	{
		chk->has_exit = true;
		vec_assign(&map->epos, vec);
	}
}

bool	set_map_entities_and_is_valid(t_map *map)
{
	t_vec		vec;
	t_checklist	chk;

	init_checklist(&chk, &vec, map);
	while (++vec.y < map->size.h)
	{
		vec.x = -1;
		while (++vec.x < map->size.w)
			check_map(map, &vec, &chk);
	}
	return (chk.has_exit && chk.has_player && chk.is_wall_valid \
			&& map->disks > 0);
}
