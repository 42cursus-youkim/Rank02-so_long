/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:18:44 by youkim            #+#    #+#             */
/*   Updated: 2021/10/07 15:49:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>

/*
** ==== Documentation ====
** refactored libft by @youkim
** only contains needed and lightweight functions
*/

typedef enum e_enum
{
	SUCCESS = 0,
	ERROR = -1,
}	t_enum;

/*
** ==== Function Name Convention ====
** [prefix]
**		y: ALL LIBFT function
** [suffix]
**		_m: uses MALLOC
**		_f: uses FREE
**			exception: all malloced pointer is freed before function exit
**
*/

#endif