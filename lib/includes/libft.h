/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:18:44 by youkim            #+#    #+#             */
/*   Updated: 2021/11/16 17:02:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>

/*	===== Documentation =====
	refactored libft by @youkim
	only contains needed and lightweight functions

	[convention]
		[comments]
			entry: ===== TEXT ===== ("=" x5)
			prototypes: ===== @Functions =====
						used as identifier in protogen
		[doc scopes]
			header: [TEXT]
			each scope is indented
*/

// ===== Marcos & Enums =====

# define SUCCESS 0
# define ERROR -1

// ===== @Functions =====
// < ystrlen.c >
int		ystrlen(char *str);

/* ===== Additional Naming Convention =====
	[prefix]
		y: ALL LIBFT function by @youkim!
	[suffix]
		_m:	uses MALLOC / dynamic allocation
			since it's the root of all memory errors
			it should be handled extra carefully
			except: all malloced pointer is freed before function exit
		_f: uses FREE
		i:	return range includes NEGATIVE INT,
			-1 based ERROR handling is not possible
*/

#endif