/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:31:27 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 13:59:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int button, int x, int y, t_engine *engine)
{
	printf("\n%sclicked button:%d x:%d y:%d%s\n", HYEL, button, x, y, END);
	walk_anim(engine);
	return (0);
}

//	 called every time a key is pressed. see e_keycode in so_long.h
int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		end_game(engine);
	if (engine->info.status == PLAY)
		player_trymove(engine, keycode);
	return (0);
}

//	called every screen refresh by mlx_loop_hook()
int	engine_update(t_engine *engine)
{
	t_map	*map;

	if (engine->info.status == SHUTDOWN)
		return (0);
	mlx_clear_window(engine->mlx, engine->win);
	map = engine->map;
	render_background(engine);
	if (engine->info.status == PLAY)
		render_tile_cond(engine, "player",
			&map->ppos, engine->info.otherwalk);
	render_enemies(engine);
	render_texts(engine);
	update_frame(&engine->info);
	return (0);
}
