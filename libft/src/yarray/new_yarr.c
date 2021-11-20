/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_yarr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:42:38 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:37:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// list of functions to allocate array, NULL terminated.
int	*new_yarr(int size)
{
	int	*arr;

	arr = malloc((size + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	arr[size] = '\0';
	return (arr);
}
