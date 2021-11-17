/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:53:01 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:13:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define TILE_SIZE 64
# define MAP_WIDTH 20
# define MAP_HEIGHT 14

# define GAME_NAME "So Long, and Thanks for All the Fish"

typedef enum e_enums
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}	t_enums;

#endif