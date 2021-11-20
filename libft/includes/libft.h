/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:55:22 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 16:45:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//	===== includes =====
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ystring.h"
# include "ysystem.h"
# include "ydict.h"

//	===== Marcos & Enums =====
# define SUCCESS 0
# define ERROR -1

/*	===== Documentation =====
	refactored libft by @youkim
	needed and lightweight functions, structured

	[comments]
		entry: ===== TEXT ===== ("=" x5)
		prototypes: ===== @Functions =====
					used as identifier in protogen
	[doc scopes]
		header: [TEXT]
		each scope is indented
	[file names prefix]
		mem: uses both NEW_ and DEL_.
	[types acronym]
		int: i, float: f, double: d, char: c, bool: b, string: s
		array: arr, pointer: ptr, function: fn
	[returns]
		default: SUCCESS: 0, ERROR: -1
		bool with 'is_': TRUE: true, FALSE: false
		string: SUCCESS: non-null value, ERROR: null
	[prefix]
		new_: uses MALLOC / dynamic allocation. somewhat c++ style.
			every malloced pointer should be freed by except for
				the pointer returned by malloc
			except: all dynamically allocated pointer is freed
				before function exit
		del_: FREE memory allocated by new
		y: ALL LIBFT function by @youkim!
	[infix]
		first 3~4 letters of directory.
		e.g y + arr + len => y_arrlen
	[suffix]
		{types}: same function but with different types
			default INT if unspecified
			new_yarrf, del_yarrll
		i / l / f:	return range includes NEGATIVE VALUES,
			-1 based ERROR handling is not possible
*/

#endif