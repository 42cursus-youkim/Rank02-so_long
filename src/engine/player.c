/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:55:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	try_collect_disk(t_map *map, t_vec *pos)
{
	if (!is_there(map, pos, DISK))
		return (0);
	map->disks--;
	map->grid[pos->y][pos->x] = GROUND;
	printf("\n%s", HGRN);
	if (map->disks == 0)
		return (printf("%s\n%s%s\n",
				"You've collected all disks!", "Go to hatch to win!", END));
	else if (map->disks > map->total_disks / 2)
		return (printf("you've collected a disk! (%zu/%zu)%s\n",
				map->disks, map->total_disks, END));
	else
		return (printf("only %zu left to go!%s\n", map->disks, END));
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
	walk_anim(engine);
}
