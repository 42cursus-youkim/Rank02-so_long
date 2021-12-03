/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:53:43 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 14:06:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del_map(t_map *map)
{
	del_ystrs(map->grid);
	del_enemies(map->enemylst);
	free(map->grid);
	free(map);
}
