/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:46:44 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 18:43:17 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// ===== @Functions =====
/* < hooks.c >
*/

int			mouse_hook(int button, int x, int y, t_game *game);
int			key_hook(int keycode, t_game *game);
int			loop_hook(t_game *game);
/* < so_long.c >
*/

void		init_map(t_game *game);
void		init_game(t_game *game);
int			end_game(int keycode, t_game *game);
#endif