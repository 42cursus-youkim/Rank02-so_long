/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:02:45 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 11:31:30 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	log_walk(t_info *info)
{
	char	*log;
	char	*walks;

	walks = new_yitoa(info->walks);
	log = new_ystrjoin((char *[]){"\rwalks: ", walks, NULL});
	ywritecolor(1, log, HMAG);
	del_ystrs((char *[]){log, walks, NULL});
}

void	print_string(t_engine *engine, char *rgb, char *str, t_vec pos)
{
	mlx_string_put(engine->mlx, engine->win, pos.x, pos.y, trgb(0, rgb), str);
}

void	render_texts(t_engine *engine)
{
	render_text(engine, (t_vec){0, 0}, "#FFFFFF",
		(char *[]){"total walks: ", new_yitoa(engine->info.walks), "", NULL});
	render_text(engine, (t_vec){0, 20},
		(char *[2]){"#FFFFFF", "#8ff58f"}[
		engine->info.collected > engine->map->disks / 2],
		(char *[]){"disks collected: ",
		new_yitoa(engine->info.collected), "/",
		new_yitoa(engine->map->disks), NULL});
}
