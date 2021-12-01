/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:06:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 20:37:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_engine *engine, char *name)
{
	t_img	*img;
	char	*path;

	path = new_ystrjoin((char *[]){"img/", name, ".xpm", NULL});
	img = malloc(sizeof(t_img));
	img->mlx = engine->mlx;
	img->data = mlx_xpm_file_to_image(
			engine->mlx, path, &img->size.w, &img->size.h);
	del_ystr(path);
	ydict_set(engine->imgs, name, img);
}

void	init_imgs(t_engine *engine, char *files[])
{
	int	i;

	engine->imgs = new_ydict(del_img);
	i = -1;
	while (files[++i])
		load_img(engine, files[i]);
}

void	del_img(void *img)
{
	t_img	*img_ptr;

	img_ptr = (t_img *)img;
	mlx_destroy_image(img_ptr->mlx, img_ptr->data);
	free(img_ptr);
}
