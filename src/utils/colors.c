/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:42:51 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 21:10:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static int	yhtoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (to_lower(c) - 'a' + 10);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//	returns trgb from given str
int	trgb(int transparency, const char *rgb)
{
	int	color;
	int	trgb[4];

	if (rgb[0] == '#')
		rgb++;
	trgb[3] = transparency;
	color = 0;
	while (++color < 4)
	{
		trgb[color] = 16 * yhtoi(rgb[2 * (color - 1)]);
		trgb[color] += yhtoi(rgb[2 * (color - 1) + 1]);
	}
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}
