/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:57:08 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 17:24:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vec_set(t_vec *v, int x, int y)
{
	v->x = x;
	v->y = y;
}

void	vec_assign(t_vec *v, t_vec *u)
{
	v->x = u->x;
	v->y = u->y;
}

void	size_set(t_size *s, int w, int h)
{
	s->w = w;
	s->h = h;
}
