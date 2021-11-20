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
# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL

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

void			del_ydictitem(t_dictitem *item);
void			del_ydict(t_dict *dict);
/*
** < new_ydict.c > */

t_dictitem		*new_ydictitem(const char *key, const char *value);
t_dict			*new_ydict(void);
/*
** < ydict_collision.c > */

void			ydict_handlecollision(t_dict *dict, t_dictitem *item);
/*
** < ydict_get.c > */

char			*ydict_get(t_dict *dict, char *key);
/*
** < ydict_set.c > */

void			ydict_set(t_dict *dict, char *key, char *value);
/*
** < yhash.c > */

uint64_t		yhash_fnv1a(const char *key);
#endif