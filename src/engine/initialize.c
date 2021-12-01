/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 14:48:26 by youkim           ###   ########.fr       */
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
