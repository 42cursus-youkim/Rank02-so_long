/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:14 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 12:33:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSYSTEM_H
# define YSYSTEM_H

// ===== @Functions =====
/*
** < yalloc.c > */

void		*ymemset(void *b, int c, size_t len);
void		ybzero(void *s, size_t n);
void		*ycalloc(size_t count, size_t size);
/*
** < yexit.c > */

void		yexit(int status);
void		yerror(char *err);
#endif