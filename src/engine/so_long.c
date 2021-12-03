/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 13:02:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	kill engine
int	end_game(t_engine *engine)
{
	engine->info.status = SHUTDOWN;
	del_ydict(engine->imgs);
	del_map(engine->map);
	mlx_destroy_window(engine->mlx, engine->win);
	printf("bye!\n");
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

static void	check_args(const int argc, const char *argv[])
{
	yassert(argc == 2, "usage: ./so_long [map]\n");
	yassert(ystrlen(argv[1]) > 4
		&& ystrequ(argv[1] + ystrlen(argv[1]) - 4, ".ber"),
		"map file should end with .ber\n");
}

//	The engine!
int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	check_args(argc, argv);
	init_engine(&engine, argv[1]);
	run_engine(&engine);
	return (0);
}
