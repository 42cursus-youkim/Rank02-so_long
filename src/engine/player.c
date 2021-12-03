/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 11:45:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_anim(t_engine *engine)
{
	engine->info.otherwalk = !engine->info.otherwalk;
}

int	try_collect_disk(t_map *map, t_vec *pos, t_info *info)
{
	if (!is_there(map, pos, DISK))
		return (0);
	info->collected++;
	map->grid[pos->y][pos->x] = GROUND;
	printf("\n%s", HGRN);
	if (info->collected == 0)
		return (printf("%s\n%s%s\n",
				"You've collected all disks!", "Go to hatch to win!", END));
	else if (map->disks > map->disks / 2)
		return (printf("you've collected a disk! (%zu/%zu)%s\n",
				info->collected, map->disks, END));
	else
		return (printf("only %zu left to go!%s\n",
				map->disks - info->collected, END));
}

void	player_trymove(t_engine *engine, int keycode)
{
	if (is_input(keycode, (t_keycode []){KEY_UP, KEY_W, KEY_K, EEND}))
		take_turn(engine, (t_vec){0, -1});
	else if (is_input(keycode, (t_keycode []){KEY_DOWN, KEY_S, KEY_J, EEND}))
		take_turn(engine, (t_vec){0, 1});
	else if (is_input(keycode, (t_keycode []){KEY_LEFT, KEY_A, KEY_H, EEND}))
		take_turn(engine, (t_vec){-1, 0});
	else if (is_input(keycode, (t_keycode []){KEY_RIGHT, KEY_D, KEY_L, EEND}))
		take_turn(engine, (t_vec){1, 0});
	else if (is_input(keycode, (t_keycode []){KEY_PERIOD, KEY_ENTER, EEND}))
		take_turn(engine, (t_vec){0, 0});
	walk_anim(engine);
}
