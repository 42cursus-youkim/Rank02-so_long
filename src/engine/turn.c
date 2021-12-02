/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:59:23 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:43:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_engine *engine, t_vec *pos)
{
	if (engine->map->disks == 0 && is_there(engine->map, pos, EXIT))
	{
		printf("\n%sYou've won!%s\n", HGRN, END);
		end_game(0, engine);
	}
}

void	check_lose(t_engine *engine, t_vec *pos, t_vec *epos)
{
	if (pos->x == epos->x && pos->y == epos->y)
	{
		printf("\n%sYou've lost!%s\n", HRED, END);
		end_game(0, engine);
	}
}

void	take_turn(t_engine *engine, int dx, int dy)
{
	t_vec	*ppos;
	t_vec	newpos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + dx, ppos->y + dy);
	if (is_there(engine->map, &newpos, WALL))
		return ;
	vec_assign(ppos, &newpos);
	check_win(engine, &newpos);
	try_enemy_act(engine, engine->map, &engine->info);
	try_collect_disk(engine->map, &newpos);
	// log_walk(&engine->info);
	engine->info.walks++;
}
