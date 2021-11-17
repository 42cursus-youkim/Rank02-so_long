/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 17:21:39 by youkim           ###   ########.fr       */
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
// mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)

int	destroy_hook(int keycode, t_game *game)
{
	// (void)keycode;
	// (void)root;
	// root_destroy(0, 0, 0);
	return (0);
}
int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook! it's %d\n", keycode);
	if (keycode == KEY_ESC)
		printf("ESC pressed, should make it quit later\n");
	return (0);
}
//	The game!
int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, destroy_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
