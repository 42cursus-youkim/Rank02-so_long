/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:58 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 16:59:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_img
{
	// struct s_engine	*engineptr;
	void			*data;
	t_size			size;
}	t_img;

typedef struct s_map
{
	t_vec	ppos;
}	t_map;

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_dict	*imgs;
	// t_img	test_img;
}	t_engine;

#endif