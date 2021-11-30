/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:28:05 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 20:06:28 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_checklist
{
	bool	has_exit;
	bool	has_player;
	bool	has_collectible;
}	t_checklist;

//	===== @Functions =====
/*
** < initialize.c > */

char		**new_loadgrid(const char *file_name);
void		place_player(t_map *map);
t_map		*init_map(const char *map_name);
/*
** < render.c > */

void		render_tile(t_engine *engine, char *key, int tilex, int tiley);
void		render_tile_anim(t_engine *engine, char *key, int tilex, int tiley);
void		render_map(t_engine *engine);
#endif