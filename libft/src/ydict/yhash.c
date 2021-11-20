/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yhash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:40:39 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 16:51:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns hashed value
int	yhash(char *str)
{
	int	i;
    int sum;

	i = -1;
	sum = 0;
    while (str[++i])
        sum += str[i];
    return sum % YDICT_INITIAL_CAPACITY;
}