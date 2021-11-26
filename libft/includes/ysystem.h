/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:14 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 11:46:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSYSTEM_H
# define YSYSTEM_H

# define BUFFER_SIZE

// ===== @Functions =====
/*
** < yalloc.c > */

void		*ymemset(void *b, int c, int len);
void		ybzero(void *s, int n);
void		*ycalloc(int count, int size);
/*
** < yexit.c > */

void		yexit(int status);
/*
** < ygnl.c > */

int			where_newline(char *backup);
int			pop_line(char **backup, char **line, int cut_where);
int			result(char **backup, char **line);
char		*ygnl(int fd);
/*
** < ylog.c > */

void		ywarn(char *warn);
void		yerror(char *where, char *err);
/*
** < ysyscall.c > */

int			ywrite(int fd, char *str);
int			ywritecolor(int fd, char *str, char *color);
#endif