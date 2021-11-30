/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:33:39 by youkim            #+#    #+#             */
/*   Updated: 2021/11/29 20:18:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRING_H
# define YSTRING_H

//	===== @Functions =====
/*
** < del_ystr.c > */

void		del_ystr(void *str);
void		del_ystrs(char *strs[]);
/*
** < func_ystr.c > */

int			ystrlen(const char *str);
int			ystrcmp(const char *s1, const char *s2);
bool		ystrequ(const char *s1, const char *s2);
int			ystrchri(const char *str, const char c);
/*
** < mod_ystr.c > */

int			ystr_append(char **pstr, char *src);
void		ystr_color(char **pstr, char *color);
void		ystr_replace(char **pstr, char *new_str);
char		*new_yslice(const char *str, int start, int end);
/*
** < new_ysplit.c > */

char		**new_ysplit(char const *s, char c);
/*
** < new_ystr.c > */

char		*new_ystr(const char *from);
char		*new_ystre(int length);
char		*new_ystrm(int length);
char		*new_yctostr(char c);
/*
** < new_ystrjoin.c > */

char		*new_ystrjoin(char *strs[]);
#endif