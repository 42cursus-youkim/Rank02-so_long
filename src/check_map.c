/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/09/27 11:03:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

int	main(void)
{
	int		fd;
	int		len;
	char	*buf;

	fd = open("map.txt", O_RDONLY);
	if (fd < 1)
	{
		printf("open failed");
		exit(1);
	}
	len = read(fd, buf, BUFFER_SIZE);
	printf("%d\n", 1);
	// printf("%d, %s\n", len, buf);
	close(fd);
}
