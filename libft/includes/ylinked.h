/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylinked.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 13:03:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLINKED_H
# define YLINKED_H

//	===== Linked List =====
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//	===== Deque =====
typedef struct s_dequenode
{
	void				*value;
	struct s_dequenode	*left;
	struct s_dequenode	*right;
}	t_dequenode;

typedef struct s_deque
{
	int			size;
	t_dequenode	*head;
	t_dequenode	*tail;
}	t_deque;

//	===== @Functions =====
/*
** < func_ylist.c > */

int				ylistlen(t_list *lst);
t_list			*ylistindex(t_list *lst, int index);
/*
** < new_ydeque.c > */

t_dequenode		*new_ydequenode(int num);
t_deque			*new_ydeque(int size, int nums[]);
/*
** < new_ylist.c > */

t_list			*new_ylist(void *content);
#endif