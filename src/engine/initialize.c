/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 18:09:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	init mlx, create window
void	init_engine(t_engine *engine)
{
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(
			engine->mlx,
			TILE_SIZE * MAP_WIDTH,
			TILE_SIZE * MAP_HEIGHT, GAME_NAME
			);
	init_imgs(engine, (char *[]){
		"space", "ground", "wall", "hatch-closed", "hatch-open",
		"alien0", "alien1", "player0", "player1", "data0", "data1", NULL});
	init_map(engine);
}

//	init map
void	init_map(t_engine *engine)
{
	engine->map = malloc(sizeof(t_map));
	if (!engine->map)
		yerror("init_map", "malloc error");
	engine->map->ppos.x = 3;
	engine->map->ppos.y = 3;
}

static void	load_img(t_engine *engine, char *name)
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

void	init_imgs(t_engine *engine, char *files[])
{
	int	i;

	engine->imgs = new_ydict(free);
	i = -1;
	while (files[++i])
		load_img(engine, files[i]);
}
