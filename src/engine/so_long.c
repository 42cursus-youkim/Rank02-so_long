/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 20:08:29 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	kill engine
int	end_game(int keycode, t_engine *engine)
{
	printf("kill them all!\n");
	exit(0);
	return (0);
}

static void	run_engine(t_engine *engine)
{
	mlx_do_key_autorepeaton(engine->mlx);
	mlx_mouse_hook(engine->win, mouse_hook, engine);
	mlx_hook(engine->win, KeyPress, KeyPressMask, key_hook, engine);
	mlx_hook(engine->win, DestroyNotify, StructureNotifyMask, end_game, engine);
	mlx_loop_hook(engine->mlx, engine_update, engine);
	mlx_loop(engine->mlx);
}

//	The engine!
int	main(int argc, char *argv[])
{
	t_engine	engine;

	// if (argc != 2)
	// {
	// 	printf("usage: ./so_long [map]\n");
	// 	return (0);
	// }
	load_map(NULL, "map/map.ber");
	// load_map(NULL, argv[1]);
	// engine.map = load_map(argv[1]);
	// init_engine(&engine);
	// run_engine(&engine);
	return (0);
}

	// mlx_destroy_window(engine.mlx, engine.win);
	//	mlx_key_hook(engine.win, key_hook, &engine);
	//	mlx_mouse_hook(engine.win, mouse_hook, &engine);
	// mlx_hook(engine.win, DestroyNotify, StructureNotifyMask, end_game, &engine);
	// mlx_loop_hook(engine.mlx, engine_update, &engine);
	// mlx_loop(engine.mlx);