/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 20:06:29 by youkim           ###   ########.fr       */
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

void	render_map(t_engine *engine)
{
	for (int i = 4; i < 10; i++)
		render_tile(engine, "wall", i, 7);
	render_tile(engine, "hatch-closed", 4, 6);
}
