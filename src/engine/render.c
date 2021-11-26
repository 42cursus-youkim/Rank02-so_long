/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:14:59 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 17:04:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_engine *engine, char *key, int tile_x, int tile_y)
{
	t_img	*img;

	img = ydict_get(engine->imgs, key);
	mlx_put_image_to_window(
		engine->mlx, engine->win, img->data,
		tile_x * TILE_SIZE, tile_y * TILE_SIZE);
}
