/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 17:26:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	check if thee tile is a wall
bool	is_wall(t_map *map, t_vec *pos)
{
	return (map->grid[pos->y][pos->x] == '1');
}

static void	player_move(t_engine *engine, int dx, int dy)
{
	t_vec	*ppos;
	t_vec	newpos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + dx, ppos->y + dy);
	if (!is_wall(engine->map, &newpos))
		vec_assign(ppos, &newpos);
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
