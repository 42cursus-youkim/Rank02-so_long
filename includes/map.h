/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:28:05 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 19:40:41 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_checklist
{
	bool	has_exit;
	bool	has_player;
	bool	has_collectible;
	bool	is_wall_valid;
}	t_checklist;

//	===== @Functions =====
/*
** < del_map.c > */

void	del_map(t_map *map);
/*
** < new_map.c > */

char	**new_loadgrid(const char *file_name);
t_map	*new_map(const char *map_name);
/*
** < render.c > */

void	render_tile(t_engine *engine, char *key, int tilex, int tiley);
void	render_tile_anim(t_engine *engine, char *key, int tilex, int tiley);
void	render_background(t_engine *engine);
void	render_map(t_engine *engine);
/*
** < valdidate.c > */

int		valdidate_map_file(t_map *map);
#endif