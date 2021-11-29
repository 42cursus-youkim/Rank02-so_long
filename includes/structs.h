/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:58 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 20:04:39 by youkim           ###   ########.fr       */
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
	char	**grid;
}	t_map;

typedef struct s_info
{
	size_t	walks;
	bool	frame;
}	t_info;

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_dict	*imgs;
	t_info	info;
}	t_engine;

#endif