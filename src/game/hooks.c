/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:31:27 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 19:03:29 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int button, int x, int y, t_game *game)
{
	printf("clicked button:%d x:%d y:%d\n", button, x, y);
	return (0);
}

//  called every time a key is pressed. see e_keycode in so_long.h
int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook! it's %d\n", keycode);
	if (keycode == KEY_ESC)
		printf("ESC pressed, should make it quit later\n");
	return (0);
}

//	called every screen refresh by mlx_loop_hook()
int	loop_hook(t_game *game)
{
	// printf("Hello from loop_hook!\n");
	mlx_put_image_to_window(game->mlx, game->win, game->test_img.data, 0, 0);
	return (0);
}
