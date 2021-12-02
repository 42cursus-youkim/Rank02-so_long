/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ymath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:46:48 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 21:18:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns how many digits the number has
int	ydigits(long long n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		n /= -10;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

//	convert input to one of -1, 0, 1
int	normalized(int n)
{
	if (n > 0)
		return (1);
	else if (n < 0)
		return (-1);
	else
		return (0);
}