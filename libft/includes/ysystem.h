/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:14 by youkim            #+#    #+#             */
/*   Updated: 2021/11/30 21:44:59 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSYSTEM_H
# define YSYSTEM_H

# define BUFFER_SIZE 20
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

char		*yreadline(int fd);
/*
** < ylog.c > */

void		ywarn(char *warn);
void		yerror(char *where, char *err);
int			ycheckerr(int statement, char *err);
void		yassert(bool statement, char *err);
/*
** < ysyscall.c > */

int			ywrite(int fd, char *str);
int			ywritecolor(int fd, char *str, char *color);
int			yread(int fd, char *buf, int buffer_size);
#endif