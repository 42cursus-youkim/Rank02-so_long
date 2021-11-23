/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:33:39 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 17:09:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRING_H
# define YSTRING_H

// ===== @Functions =====
/*
** < del_ystr.c > */

void		del_ystr(char *str);
void		del_ystrs(char *strs[]);
/*
** < func_ystr.c > */

int			ystrlen(const char *str);
int			ystrcmp(const char *s1, const char *s2);
bool		ystrequ(const char *s1, const char *s2);
/*
** < mod_ystr.c > */

int			ystr_cat(char *dest, const char *src);
void		ystr_color(char **pstr, char *color);
/*
** < new_ystr.c > */

char		*new_ystr(const char *from);
char		*new_ystre(int length);
char		*new_ystrm(int length);
/*
** < new_ystrjoin.c > */

char		*new_ystrjoin(char *strs[]);
#endif