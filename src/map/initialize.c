/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 18:25:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_loadgrid(const char *file_name)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	**grid;

	fd = ycheckerr(open(file_name, O_RDONLY), "invalid map name!!!");
	line = new_ystr("");
	while (true)
	{
		buffer = yreadline(fd);
		if (!buffer)
			break ;
		ystr_append(&line, buffer);
	}
	grid = new_ysplit(line, '\n');
	close(fd);
	return (grid);
}

void	place_player(t_map *map)
{
	map->ppos.x = 3;
	map->ppos.y = 3;
}
// int	valdidate_map_file(, t_map *map)
// {
// 	int		fd;

// 	map->grid = load_grid(fd);
// 	return (SUCCESS);
// }
