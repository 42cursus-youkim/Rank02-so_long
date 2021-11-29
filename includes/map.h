/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:28:05 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 17:57:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H


//	===== @Functions =====
/*
** < load.c > */

void		load_map(t_map *map, char *file_name);
/*
** < render.c > */

void		render_tile(t_engine *engine, char *key, int tilex, int tiley);
void		render_tile_animated(t_engine *engine, char *key, int tilex, int tiley);
void		render_map(t_engine *engine);
#endif