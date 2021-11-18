/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:20:55 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 11:42:38 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"

//length of a string. null termination is not counted.
int	ystrlen(const char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
