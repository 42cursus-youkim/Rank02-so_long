/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 20:34:04 by youkim           ###   ########.fr       */
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

static void	set_map_size(t_map *map)
{
	size_set(&map->size, 0, -1);
	while (map->grid[++map->size.h])
		while (map->grid[map->size.h][map->size.w])
			map->size.w++;
}

t_map	*init_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->symbols = new_ydictinits(del_ystr,
			(char *[]){"0", "1", "C", "E", "P", NULL}, \
			(char *[]){"ground", "wall", "data0",
			"hatch-closed", "player0", NULL});
	ydict_list_items(map->symbols);
	map->grid = new_loadgrid(map_name);
	set_map_size(map);
	// yassert(valdidate_map_file(map) == SUCCESS, "invalid map!");
	place_player(map);
	return (map);
}
