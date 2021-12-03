/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:59:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 13:50:19 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

//	===== @Functions =====
/*
** < colors.c > */

int		create_trgb(int t, int r, int g, int b);
int		trgb(int transparency, const char *rgb);
/*
** < texts.c > */

void	log_walk(t_info *info);
void	print_string(t_engine *engine, char *rgb, char *str, t_vec pos);
void	render_texts(t_engine *engine);
/*
** < utils.c > */

void	update_frame(t_info *info);
bool	is_there(t_map *map, t_vec *pos, char thing);
bool	is_input(t_keycode input, t_keycode keys[]);
/*
** < vectors.c > */

void	vec_set(t_vec *v, int x, int y);
void	vec_assign(t_vec *v, t_vec *f);
void	vec_update(t_vec *v, int dx, int dy);
void	size_set(t_size *s, int w, int h);
void	size_assign(t_size *s, t_size *f);
#endif