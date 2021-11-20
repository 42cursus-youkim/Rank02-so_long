/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:20:55 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 13:47:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"

//length of a string. null termination is not counted.
int	ystrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
