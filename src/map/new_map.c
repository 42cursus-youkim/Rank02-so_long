/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:08:33 by youkim           ###   ########.fr       */
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
		del_ystr(buffer);
	}
	grid = new_ysplit(line, '\n');
	close(fd);
	del_ystrs((char *[]){line, buffer, NULL});
	return (grid);
}

t_map	*new_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->grid = new_loadgrid(map_name);
	map->charmap = new_ycharmap(
			(char []){GROUND, WALL, '\0'},
			(char *[]){"ground", "wall", NULL});
	yassert(set_map_size_and_is_valid(map), "map is not rectangular!");
	yassert(set_map_entities_and_is_valid(map), "invalid map!");
	return (map);
}
