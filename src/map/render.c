/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 21:48:51 by youkim           ###   ########.fr       */
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
				render_tile_cond(engine, "hatch", &vec, map->disks <= 0);
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

void	render_texts(t_engine *engine)
{
	render_text(engine, "#FFFFFF", (t_vec){0, 0},
		(char *[]){"total walks: ", new_yitoa(engine->info.walks), "", NULL});
	render_text(engine, "#8ff58f", (t_vec){0, 20},
		(char *[]){"disks collected: ",
		new_yitoa(engine->map->total_disks - engine->map->disks), "/",
		new_yitoa(engine->map->total_disks), NULL});
}
