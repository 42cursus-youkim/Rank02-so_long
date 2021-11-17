/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:46:44 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:23:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// ===== @Functions =====
// < so_long.c >

void		init_map(t_game *game);
void		init_game(t_game *game);
int			destroy_hook(int keycode, t_game *game);
int			key_hook(int keycode, t_game *game);

#endif