/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ygnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:37 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 19:32:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	where_newline(char *backup)
{
	int	i;

	i = -1;
	while (backup[++i])
		if (backup[i] == '\n')
			return (i);
	return (-1);
}

int	pop_line(char **backup, char **line, int cut_where)
{
	char	*temp;

	(*backup)[cut_where] = '\0';
	*line = ft_strdup(*backup);
	if (!ft_strlen(*backup + cut_where + 1))
	{
		free(*backup);
		*backup = 0;
	}
	else
	{
		temp = ft_strdup(*backup + cut_where + 1);
		free(*backup);
		*backup = temp;
	}
	return (1);
}

int	result(char **backup, char **line)
{
	int	cut_where;

	cut_where = where_newline(*backup);
	if (*backup && cut_where >= 0)
		return (pop_line(backup, line, cut_where));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

//	returns A LINE of TEXT from File Discriptor
char	*ygnl(int fd)
{
	int			len;
	int			cut_where;
	char		buffer[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (ERROR);
	while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buffer);
		if ((cut_where = where_newline(backup[fd])) >= 0)
			return (pop_line(&backup[fd], line, cut_where));
	}
	if (len < 0)
		return (NULL);
	return (result(&backup[fd], line));
}

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1

int main(void)
{
	char buf[BUFFER_SIZE + 1];
	char *save;
	int fd;
	int read_size = 0;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[read_size] = '\0';
			if(save == NULL)
				save = strdup(buf);
			else
				strcat(save, buf);
		}
		printf("%s", save);
		close(fd);
	}
	return(0);
}