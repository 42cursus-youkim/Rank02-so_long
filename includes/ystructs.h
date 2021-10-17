/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystructs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:58 by youkim            #+#    #+#             */
/*   Updated: 2021/10/11 12:15:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRUCTS_H
# define YSTRUCTS_H

/*
** ===== Main Data Structures =====
*/
typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;

typedef enum e_enum_sl
{
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