/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:40:56 by youkim            #+#    #+#             */
/*   Updated: 2021/10/07 15:38:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>

/*
** === Main Data Structures ===
*/
typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;
typedef enum e_enum_sl
{
	ERROR = -1,
	TILE_WIDTH = 80,
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}	t_enum_sl;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;
typedef struct s_map
{
	t_vec	size;
	t_vec	ppos;
}	t_map;

#endif