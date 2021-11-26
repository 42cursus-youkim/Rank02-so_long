/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:14 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 13:01:39 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSYSTEM_H
# define YSYSTEM_H

# define BUFFER_SIZE 42
# define OPEN_MAX 128
//	===== @Functions =====
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