/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:46:44 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 16:22:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//	===== @Functions =====
/*
** < hooks.c > */

int		mouse_hook(int button, int x, int y, t_engine *engine);
int		key_hook(int keycode, t_engine *engine);
int		engine_update(t_engine *engine);
/*
** < images.c > */

void	init_imgs(t_engine *engine, char *files[]);
void	del_img(void *img);
/*
** < initialize.c > */

void	init_engine(t_engine *engine, const char *map_name);
/*
** < player.c > */

void	player_trymove(t_engine *engine, int keycode);
/*
** < so_long.c > */

int		end_game(int keycode, t_engine *engine);
/*
** < turn.c > */

void	take_turn(t_engine *engine, int dx, int dy);
#endif