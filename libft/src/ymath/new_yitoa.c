/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_yitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:45:25 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:10:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_yitoa(int n)
{
	char	*str;
	int		digit;
	long	num;

	num = n;
	if (num == 0)
		return (new_ystr("0"));
	digit = ydigits(num);
	if (num < 0)
		digit++;
	str = new_ystrm(digit);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--digit] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
