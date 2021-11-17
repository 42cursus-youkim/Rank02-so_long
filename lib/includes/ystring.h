/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:33:39 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:38:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRING_H
# define YSTRING_H

// ===== @Functions =====
// < del_ystr.c >

void		del_ystr(char *str);

// < new_ystr.c >

char		*new_ystr(const char *from);
char		*new_ystre(int length);

// < new_ystrjoin.c >

char		*new_ystrjoin(char *strs[]);

// < oper_ystr.c >

int			ystrcat(char *dest, const char *src);

// < ystrlen.c >

int			ystrlen(const char *str);

#endif