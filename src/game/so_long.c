/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 19:05:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	init map
void	init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		yerror("malloc error");
}

//	init mlx, create window
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(
			game->mlx,
			TILE_SIZE * MAP_WIDTH,
			TILE_SIZE * MAP_HEIGHT, GAME_NAME
			);
}

//	kill game
int	end_game(int keycode, t_game *game)
{
	printf("kill them all!\n");
	exit(0);
	return (0);
}

//	The game!
int	main(int argc, char *argv[])
{
	t_game	game;
	
	init_game(&game);
	game.test_img.data = mlx_xpm_file_to_image(game.mlx, "img/test.xpm", &game.test_img.data, &game.test_img.data);
	// mlx_key_hook(game.win, key_hook, &game);
	// mlx_mouse_hook(game.win, mouse_hook, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, end_game, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
}
