/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 11:33:59 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_engine *engine)
{
	t_vec	vec;
	t_map	*map;

	map = engine->map;
	vec.y = -1;
	while (++vec.y < map->size.h)
	{
		vec.x = -1;
		while (++vec.x < map->size.w)
		{
			render_tile(engine, "ground", &vec);
			if (map->grid[vec.y][vec.x] == WALL)
				render_tile(engine, "wall", &vec);
			else if (map->grid[vec.y][vec.x] == EXIT)
				render_tile_cond(engine, "hatch", &vec,
					engine->info.collected == map->disks);
			else if (map->grid[vec.y][vec.x] == DISK)
				render_tile_anim(engine, "data", &vec);
		}
	}
}

void	render_enemies(t_engine *engine)
{
	int	id;

	id = -1;
	while (engine->map->enemylst[++id])
		render_tile_anim(engine, "enemy", engine->map->enemylst[id]);
}
