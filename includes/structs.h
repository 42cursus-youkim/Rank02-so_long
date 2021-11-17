/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:58 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:14:08 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//	===== Basic Data structures =====
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_size
{
	int	w;
	int	h;
}	t_size;

//	===== Complex Data structures =====
typedef struct s_map
{
	t_vec	ppos;
	t_size	size;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_game;

#endif