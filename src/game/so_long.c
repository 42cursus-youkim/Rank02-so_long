/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:37:29 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:10:08 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

//	The game!
int	main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
