/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:52:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 12:35:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define FRAME_CYCLE 30

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
	void	*data;
	void	*mlx;
	t_size	size;
}	t_img;

typedef struct s_map
{
	t_vec	ppos;
	t_vec	epos;
	t_vec	**enemylst;
	t_size	size;
	char	**grid;
	size_t	disks;
	size_t	total_disks;
}	t_map;

typedef struct s_info
{
	int		frames;
	bool	otherwalk;
	bool	otherturn;
	size_t	walks;
	bool	end;
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