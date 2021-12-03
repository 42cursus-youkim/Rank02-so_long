/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:25:30 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 11:58:39 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_engine *engine, char *key, t_vec *vec)
{
	t_img	*img;

	img = ydict_get(engine->imgs, key);
	if (!img)
		yerror("render_tile", "invlaid image!");
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

//	char *texts[] => const, malloc, const, malloc, ..., NULL
void	render_text(t_engine *engine, t_vec vec, char *rgb, char *texts[])
{
	int		i;
	char	*text;

	i = 0;
	text = new_ystrjoin(texts);
	print_string(engine, rgb, text, vec);
	while (texts[++i])
		if (i % 2 && texts[i])
			del_ystr(texts[i]);
	del_ystr(text);
}

void	walk_anim(t_engine *engine)
{
	engine->info.otherwalk = !engine->info.otherwalk;
}
