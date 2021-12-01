/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 16:51:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_engine *engine, char *key, int tilex, int tiley)
{
	t_img	*img;

	img = ydict_get(engine->imgs, key);
	mlx_put_image_to_window(
		engine->mlx, engine->win, img->data,
		tilex * TILE_SIZE, tiley * TILE_SIZE);
}

void	render_tile_anim(t_engine *engine, char *key, int tilex, int tiley)
{
	char	*anim_key;
	char	*frame;

	frame = new_yitoa(engine->info.frame);
	anim_key = new_ystrjoin((char *[]){key, frame, NULL});
	render_tile(engine, anim_key, tilex, tiley);
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
			name = map->charmap[(int)map->grid[vec.y][vec.x]];
			if (name && !ystrequ(name, "player"))
				render_tile(engine, name, vec.x, vec.y);
		}
	}
}

void	render_map(t_engine *engine)
{
	render_background(engine);
	// render_tile(engine, "wall", 1, 1);
	// render_tile(engine, "hatch-closed", 4, 3);
}
