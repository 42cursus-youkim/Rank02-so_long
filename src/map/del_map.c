/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:53:43 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 15:13:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del_map(t_map *map)
{
	del_ystrs(map->grid);
	free(map->grid);
	free(map);
}
