/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 21:53:04 by youkim           ###   ########.fr       */
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

void	place_player(t_map *map)
{
	t_vec	vec;

	vec.y = -1;
	while (++vec.y < map->size.h)
	{
		vec.x = -1;
		while (++vec.x < map->size.w)
		{
			if (map->grid[vec.y][vec.x] == 'P')
			{
				map->ppos.x = vec.x;
				map->ppos.y = vec.y;
				map->grid[vec.y][vec.x] = ' ';
				return ;
			}
		}
	}
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

t_map	*new_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->symbols = new_ydictinits(del_ystr,
			(char *[]){"0", "1", NULL}, \
			(char *[]){"ground", "wall", NULL});
	ydict_list_items(map->symbols);
	map->grid = new_loadgrid(map_name);
	set_map_size(map);
	place_player(map);
	// yassert(valdidate_map_file(map) == SUCCESS, "invalid map!");
	return (map);
}
