/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 19:28:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	init map
void	init_map(t_engine *engine)
{
	engine->map = malloc(sizeof(t_map));
	if (!engine->map)
		yerror("init_map", "malloc error");
	engine->map->ppos.x = 3;
	engine->map->ppos.y = 3;
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
	init_map(engine);
}

void	new_img(t_engine *engine, char *name)
{
	t_img	*img;
	char	*path;

	path = new_ystrjoin((char *[]){"img/", name, ".xpm", NULL});
	img = malloc(sizeof(t_img));
	img->data = mlx_xpm_file_to_image(
			engine->mlx, path, &img->size.w, &img->size.h);
	del_ystr(path);
	ydict_set(engine->imgs, name, img);
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
	new_img(&engine, "test");
	mlx_do_key_autorepeaton(engine.mlx);
	// mlx_key_hook(engine.win, key_hook, &engine);
	// mlx_mouse_hook(engine.win, mouse_hook, &engine);
	mlx_hook(engine.win, KeyPress, KeyPressMask, key_hook, &engine);
	mlx_hook(engine.win, DestroyNotify, StructureNotifyMask, end_game, &engine);
	mlx_loop_hook(engine.mlx, engine_update, &engine);
	mlx_loop(engine.mlx);
	while(1) {}
	return (0);
}


	// init_engine(&engine);
	// printf("will remove dict\n");
	// new_img(&engine, "test");
	// mlx_destroy_window(engine.mlx, engine.win);
	// printf("removed dict\n");
	// del_ydict(engine.imgs);
	//	mlx_key_hook(engine.win, key_hook, &engine);
	//	mlx_mouse_hook(engine.win, mouse_hook, &engine);
	// mlx_hook(engine.win, DestroyNotify, StructureNotifyMask, end_game, &engine);
	// mlx_loop_hook(engine.mlx, engine_update, &engine);
	// mlx_loop(engine.mlx);