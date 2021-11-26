/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 17:02:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	init map
void	init_map(t_engine *engine)
{
	engine->map = malloc(sizeof(t_map));
	if (!engine->map)
		yerror("init_map", "malloc error");
}

//	init mlx, create window
void	init_engine(t_engine *engine)
{
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(
			engine->mlx,
			TILE_SIZE * MAP_WIDTH,
			TILE_SIZE * MAP_HEIGHT, GAME_NAME
			);
	engine->imgs = new_ydict(free);
}

// void	new_img(t_engine *engine)
// {
// 	engine->test_img.engineptr = engine;
// 	engine->test_img.data = mlx_xpm_file_to_image(
// 			engine->mlx, "img/test.xpm",
// 			&engine->test_img.size.w, &engine->test_img.size.h);
// }

void	new_img(t_engine *engine)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->data = mlx_xpm_file_to_image(
			engine->mlx, "img/test.xpm",
			&img->size.w, &img->size.h);
	ydict_set(engine->imgs, "test", img);
	// engine->test_img.data = mlx_xpm_file_to_image(
	// 		engine->mlx, "img/test.xpm",
	// 		&engine->test_img.size.w, &engine->test_img.size.h);
}

//	kill engine
int	end_game(int keycode, t_engine *engine)
{
	printf("kill them all!\n");
	exit(0);
	return (0);
}

//	The engine!
int	main(int argc, char *argv[])
{
	t_engine	engine;

	init_engine(&engine);
	new_img(&engine);
	//	mlx_key_hook(engine.win, key_hook, &engine);
	//	mlx_mouse_hook(engine.win, mouse_hook, &engine);
	mlx_hook(engine.win, DestroyNotify, StructureNotifyMask, end_game, &engine);
	mlx_loop_hook(engine.mlx, engine_update, &engine);
	mlx_loop(engine.mlx);
}
