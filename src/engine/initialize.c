/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 12:10:45 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_info(t_info *info)
{
	info->walks = 0;
	info->frames = 0;
	info->otherwalk = false;
	info->otherturn = false;
}

//	init mlx, create window
void	init_engine(t_engine *engine, const char *map_name)
{
	engine->map = new_map(map_name);
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(
			engine->mlx,
			TILE_SIZE * engine->map->size.w,
			TILE_SIZE * engine->map->size.h, GAME_NAME
			);
	init_info(&engine->info);
	init_imgs(engine, (char *[]){
		"ground", "wall", "hatch0", "hatch1",
		"enemy0", "enemy1", "player0", "player1", "data0", "data1", NULL});
}
