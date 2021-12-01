/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:28:05 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:08:45 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define DISK 'C'
# define EXIT 'E'
typedef struct s_checklist
{
	bool	has_exit;
	bool	has_player;
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

void	render_tile(t_engine *engine, char *key, t_vec *vec);
void	render_tile_anim(t_engine *engine, char *key, t_vec *vec);
void	render_tile_cond(t_engine *engine, char *key, t_vec *vec, bool cond);
void	render_background(t_engine *engine);
void	render(t_engine *engine);
/*
** < valdidate.c > */

bool	set_map_size_and_is_valid(t_map *map);
bool	set_map_entities_and_is_valid(t_map *map);
#endif