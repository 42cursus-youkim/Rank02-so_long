/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:31:27 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 17:56:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int button, int x, int y, t_engine *engine)
{
	printf("clicked button:%d x:%d y:%d\n", button, x, y);
	return (0);
}

void	player_move(t_engine *engine, int keycode)
{
	if (keycode == KEY_UP)
		engine->map->ppos.y -= 1;
	if (keycode == KEY_DOWN)
		engine->map->ppos.y += 1;
	if (keycode == KEY_LEFT)
		engine->map->ppos.x -= 1;
	if (keycode == KEY_RIGHT)
		engine->map->ppos.x += 1;
}

//	 called every time a key is pressed. see e_keycode in so_long.h
int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		end_game(keycode, engine);
	if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		player_move(engine, keycode);
	return (0);
}

//	called every screen refresh by mlx_loop_hook()
int	engine_update(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->win);
	render_tile(engine, "hatch-closed", 4, 6);
	render_tile(engine, "player0", engine->map->ppos.x, engine->map->ppos.y);
	return (0);
}
