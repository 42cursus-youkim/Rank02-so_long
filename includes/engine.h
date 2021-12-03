/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:46:44 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 12:50:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//	===== @Functions =====
/*
** < enemies.c > */

bool	is_there_enemy(t_map *map, t_vec *pos);
void	del_enemies(t_vec **enemylst);
void	init_enemies(t_map *map);
/*
** < enemy.c > */

void	try_move_manhattan(t_map *map, t_vec *epos, t_vec d);
void	try_enemy_act(t_engine *engine, t_vec *epos, t_map *map, bool do_act);
/*
** < images.c > */

void	init_imgs(t_engine *engine, char *files[]);
void	del_img(void *img);
/*
** < initialize.c > */

void	init_engine(t_engine *engine, const char *map_name);
/*
** < player.c > */

int		try_collect_disk(t_map *map, t_vec *pos, t_info *info);
void	player_trymove(t_engine *engine, int keycode);
/*
** < so_long.c > */

int		end_game(t_engine *engine);
/*
** < turn.c > */

void	check_win(t_engine *engine, t_vec *pos);
void	check_lose(t_engine *engine, t_vec *pos, t_vec *epos);
void	enemies_turn(t_engine *engine, t_map *map, t_info *info);
void	player_turn(t_engine *engine, t_info *info, t_vec d);
void	take_turn(t_engine *engine, t_vec d);
/*
** < updates.c > */

int		mouse_hook(int button, int x, int y, t_engine *engine);
int		key_hook(int keycode, t_engine *engine);
int		engine_update(t_engine *engine);
#endif