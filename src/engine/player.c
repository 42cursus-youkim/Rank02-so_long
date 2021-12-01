/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:39:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	try_collect_disk(t_map *map, t_vec *pos)
{
	if (!is_there(map, pos, DISK))
		return ;
	map->disks--;
	map->grid[pos->y][pos->x] = GROUND;
	printf("\n%syou've collected a disk!%s\n", HGRN, END);
}

static void	check_win(t_engine *engine, t_vec *pos)
{
	if (engine->map->disks == 0 && is_there(engine->map, pos, EXIT))
	{
		printf("\n%sYou've won!%s\n", HGRN, END);
		end_game(0, engine);
	}
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
	check_win(engine, &newpos);
	handle_walks(&engine->info);
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
