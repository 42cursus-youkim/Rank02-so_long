/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:59:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 17:23:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
//	===== @Functions =====
/*
** < vectors.c > */

void	vec_set(t_vec *v, int x, int y);
void	vec_assign(t_vec *v, t_vec *u);
void	size_set(t_size *s, int w, int h);
#endif