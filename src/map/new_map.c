/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 12:06:45 by youkim           ###   ########.fr       */
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

void	spawn_enemies(t_map *map)
{
	int		id;
	t_vec	vec;

	id = 0;
	vec_set(&vec, -1, -1);
	while (map->grid[++vec.y])
	{
		vec.x = -1;
		while (map->grid[vec.y][++vec.x])
			if (map->grid[vec.y][vec.x] == DISK)
				vec_assign(map->enemylst[id++], &vec);
	}
}

t_map	*new_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->grid = new_loadgrid(map_name);
	yassert(set_map_size_and_is_valid(map), "map is not rectangular!");
	yassert(set_map_entities_and_is_valid(map), "invalid map!");
	init_enemies(map);
	spawn_enemies(map);
	return (map);
}
