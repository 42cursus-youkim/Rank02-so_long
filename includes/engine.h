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

int			mouse_hook(int button, int x, int y, t_engine *engine);
int			key_hook(int keycode, t_engine *engine);
int			engine_update(t_engine *engine);
/*
** < render.c > */

void		render_tile(t_engine *engine, char *key, int tile_x, int tile_y);
/*
** < so_long.c > */

void		init_map(t_engine *engine);
void		init_engine(t_engine *engine);
void		new_img(t_engine *engine);
int			end_game(int keycode, t_engine *engine);
#endif