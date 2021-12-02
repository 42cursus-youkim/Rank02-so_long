/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:42:59 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	kill engine
int	end_game(int keycode, t_engine *engine)
{
	keycode = 0;
	printf("bye!\n");
	if (engine || !engine)
		exit(0);
	return (0);
}

static void	run_engine(t_engine *engine)
{
	mlx_do_key_autorepeaton(engine->mlx);
	mlx_mouse_hook(engine->win, mouse_hook, engine);
	mlx_hook(engine->win, KeyPress, KeyPressMask, key_hook, engine);
	mlx_hook(engine->win, DestroyNotify, NoEventMask, end_game, engine);
	mlx_loop_hook(engine->mlx, engine_update, engine);
	mlx_loop(engine->mlx);
}

//	The engine!
int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	yassert(argc == 2, "usage: ./so_long [map]\n");
	init_engine(&engine, argv[1]);
	run_engine(&engine);
	return (0);
}

	// mlx_destroy_window(engine.mlx, engine.win);
	//	mlx_key_hook(engine.win, key_hook, &engine);
	//	mlx_mouse_hook(engine.win, mouse_hook, &engine);
	// mlx_hook(engine.win, DestroyNotify, StructureNotifyMask, end_game, &engine);
	// mlx_loop_hook(engine.mlx, engine_update, &engine);
	// mlx_loop(engine.mlx);