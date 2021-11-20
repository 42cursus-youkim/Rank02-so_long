/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yhashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:29:34 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 12:28:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YDICT_H
# define YDICT_H

# define YDICT_INITIAL_CAPACITY 2

typedef struct s_dictitem
{
	char	*key;
	char	*value;
}	t_dictitem;

typedef struct s_dict
{
	t_dictitem	**items;
	size_t		size;
	size_t		capacity;
}	t_dict;

// ===== @Functions =====
/*
** < del_ydict.c > */

void		del_ydictitem(t_dictitem *item);
void		del_ydict(t_dict *dict);
/*
** < new_ydict.c > */

t_dict		*new_ydict(void);
/*
** < yhash.c > */

int			yhash(char *str);
#endif