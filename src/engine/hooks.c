/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:31:27 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:11:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int button, int x, int y, t_engine *engine)
{
	printf("%sclicked button:%d x:%d y:%d%s\n", HYEL, button, x, y, END);
	walk_anim(engine);
	return (0);
}

//	 called every time a key is pressed. see e_keycode in so_long.h
int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		end_game(keycode, engine);
	player_trymove(engine, keycode);
	walk_anim(engine);
	return (0);
}

//	called every screen refresh by mlx_loop_hook()
int	engine_update(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->win);
	render_map(engine);
	if (engine->info.otherwalk)
		render_tile(engine, "player0", &engine->map->ppos);
	else
		render_tile(engine, "player1", &engine->map->ppos);
	update_frame(&engine->info);
	return (0);
}
