/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 09:59:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_trymove(t_engine *engine, int keycode)
{
	if (is_input(keycode, (t_keycode []){KEY_UP, KEY_W, KEY_K, EEND}))
		take_turn(engine, 0, -1);
	if (is_input(keycode, (t_keycode []){KEY_DOWN, KEY_S, KEY_J, EEND}))
		take_turn(engine, 0, 1);
	if (is_input(keycode, (t_keycode []){KEY_LEFT, KEY_A, KEY_H, EEND}))
		take_turn(engine, -1, 0);
	if (is_input(keycode, (t_keycode []){KEY_RIGHT, KEY_D, KEY_L, EEND}))
		take_turn(engine, 1, 0);
}
