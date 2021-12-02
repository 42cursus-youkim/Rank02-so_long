/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:40:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_collect_disk(t_map *map, t_vec *pos)
{
	if (!is_there(map, pos, DISK))
		return ;
	map->disks--;
	map->grid[pos->y][pos->x] = GROUND;
	printf("\n%syou've collected a disk!%s\n", HGRN, END);
}

void	player_trymove(t_engine *engine, int keycode)
{
	if (is_input(keycode, (t_keycode []){KEY_UP, KEY_W, KEY_K, EEND}))
		take_turn(engine, 0, -1);
	if (is_input(keycode, (t_keycode []){KEY_DOWN, KEY_S, KEY_J, EEND}))
		take_turn(engine, 0, 1);
	if (is_input(keycode, (t_keycode []){KEY_LEFT, KEY_A, KEY_H, EEND}))
		take_turn(engine, -1, 0);
	if (is_input(keycode, (t_keycode []){KEY_RIGHT, KEY_D, KEY_L, EEND}))
		take_turn(engine, 1, 0);
}
