/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:20:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_anim(t_engine *engine)
{
	engine->info.otherwalk = !engine->info.otherwalk;
}

static void	try_collect_disk(t_map *map, t_vec *vec)
{
	if (!is_there(map, vec, DISK))
		return ;
	map->disks--;
	map->grid[vec->y][vec->x] = GROUND;
}

static void	player_move(t_engine *engine, int dx, int dy)
{
	t_vec	*ppos;
	t_vec	newpos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + dx, ppos->y + dy);
	if (is_there(engine->map, &newpos, WALL))
		return ;
	try_collect_disk(engine->map, &newpos);
	vec_assign(ppos, &newpos);
	engine->info.walks++;
	printf("%swalks: %zu%s\n", HGRN, engine->info.walks, END);
}

void	player_trymove(t_engine *engine, int keycode)
{
	if (!(KEY_LEFT <= keycode && keycode <= KEY_UP))
		return ;
	if (keycode == KEY_UP)
		player_move(engine, 0, -1);
	if (keycode == KEY_DOWN)
		player_move(engine, 0, 1);
	if (keycode == KEY_LEFT)
		player_move(engine, -1, 0);
	if (keycode == KEY_RIGHT)
		player_move(engine, 1, 0);
}
