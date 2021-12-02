/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:57:08 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 10:43:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vec_set(t_vec *v, int x, int y)
{
	v->x = x;
	v->y = y;
}

void	vec_assign(t_vec *v, t_vec *f)
{
	v->x = f->x;
	v->y = f->y;
}

void	vec_update(t_vec *v, int dx, int dy)
{
	v->x += dx;
	v->y += dy;
}

void	size_set(t_size *s, int w, int h)
{
	s->w = w;
	s->h = h;
}

void	size_assign(t_size *s, t_size *f)
{
	s->w = f->w;
	s->h = f->h;
}
