/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:36:15 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_engine *engine, char *key, t_vec *vec)
{
	t_img	*img;

	img = ydict_get(engine->imgs, key);
	mlx_put_image_to_window(
		engine->mlx, engine->win, img->data,
		vec->x * TILE_SIZE, vec->y * TILE_SIZE);
}

void	render_tile_anim(t_engine *engine, char *key, t_vec *vec)
{
	render_tile_cond(engine, key, vec, engine->info.frames > FRAME_CYCLE / 2);
}

void	render_tile_cond(t_engine *engine, char *key, t_vec *vec, bool cond)
{
	char	*anim_key;
	char	*frame;

	frame = new_yitoa((int)cond);
	anim_key = new_ystrjoin((char *[]){key, frame, NULL});
	render_tile(engine, anim_key, vec);
	del_ystrs((char *[]){anim_key, frame, NULL});
}

void	render_background(t_engine *engine)
{
	t_vec	vec;
	t_map	*map;
	char	*name;

	map = engine->map;
	vec.y = -1;
	while (++vec.y < map->size.h)
	{
		vec.x = -1;
		while (++vec.x < map->size.w)
		{
			if (map->grid[vec.y][vec.x] == EXIT)
				render_tile_cond(engine, "hatch", &vec, map->disks <= 0);
			if (map->grid[vec.y][vec.x] == DISK)
				render_tile_anim(engine, "data", &vec);
			name = map->charmap[(int)map->grid[vec.y][vec.x]];
			if (name && !ystrequ(name, "player"))
				render_tile(engine, name, &vec);
		}
	}
}

void	render(t_engine *engine)
{
	render_background(engine);
	render_tile_cond(engine, "player",
		&engine->map->ppos, engine->info.otherwalk);
	update_frame(&engine->info);
}
