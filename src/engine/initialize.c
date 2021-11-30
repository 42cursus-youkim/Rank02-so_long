/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 20:05:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	init mlx, create window
void	init_engine(t_engine *engine, t_map *map)
{
	engine->map = map;
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(
			engine->mlx,
			TILE_SIZE * map->size.w,
			TILE_SIZE * map->size.h, GAME_NAME
			);
	engine->info.frame = false;
	init_imgs(engine, (char *[]){
		"space", "ground", "wall", "hatch-closed", "hatch-open",
		"alien0", "alien1", "player0", "player1", "data0", "data1", NULL});
}

//	init map
t_map	*init_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->grid = new_loadgrid(map_name);
	size_set(&map->size, 0, -1);
	while (map->grid[++map->size.h])
		while (map->grid[map->size.h][map->size.w])
			map->size.w++;
	// yassert(valdidate_map_file(map) == SUCCESS, "invalid map!");
	place_player(map);
	return (map);
}
