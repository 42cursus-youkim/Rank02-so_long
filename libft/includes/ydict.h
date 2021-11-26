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

# include "yconfig.h"

# define YDICT_INITIAL_CAPACITY 8
# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL
typedef struct s_dictitem
{
	char	*key;
	void	*value;
}	t_dictitem;

typedef struct s_dict
{
	int				size;
	int				capacity;
	t_dictitem		**items;
	t_destructor_f	del_value;
}	t_dict;

// ===== @Functions =====
/*
** < del_ydict.c > */

void			del_ydictitem(t_dict *dict, int id);
void			del_ydict(t_dict *dict);
/*
** < new_ydict.c > */

t_dictitem		*new_ydictitem(const char *key, void *value);
t_dictitem		**new_ydictitem_arr(int capacity);
t_dict			*new_ydict(t_destructor_f del_value);
/*
** < ydict_expand.c > */

int				ydict_expand(t_dict *dict);
/*
** < ydict_get.c > */

int				ydict_getid(int capacity, char *key);
char			*ydict_get(t_dict *dict, char *key);
char			*ydict_getd(t_dict *dict, char *key, char *defaultv);
/*
** < ydict_property.c > */

void			ydict_list_items(t_dict *dict);
/*
** < ydict_set.c > */

void			ydict_set(t_dict *dict, char *key, void *value);
void			ydict_setstr(t_dict *dict, char *key, char *value);
/*
** < ydict_status.c > */

bool			is_input_valid(t_dict *dict, char *key, void *value);
bool			is_key_vacant(t_dict *dict, int id);
bool			is_key_update(t_dict *dict, int id, char *key);
bool			is_dict_almostfull(t_dict *dict);
bool			is_capacity_overflow(t_dict *dict);
/*
** < yhash.c > */

uint64_t		yhash_fnv1a(const char *key);
#endif