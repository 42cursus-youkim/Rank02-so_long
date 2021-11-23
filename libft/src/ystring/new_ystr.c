/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:26:06 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 13:09:03 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	copy a string. equivalent to strdup()
	use NULL TERMINATED STRING if you'r passing it implicitly!!!
*/
char	*new_ystr(const char *from)
{
	int		i;
	char	*str;

	i = ystrlen(from);
	str = new_ystrm(i);
	if (!str)
		return (NULL);
	while (i-- > 0)
		str[i] = from[i];
	return (str);
}

/*	create an empty null-terminated string.
	empty spaces are filled with ' ', so it can fe safely deleted.
*/
char	*new_ystre(int length)
{
	char	*str;

	str = new_ystrm(length);
	if (!str)
		return (NULL);
	while (length-- > 0)
		str[length] = ' ';
	return (str);
}

/*	create an NULL-terminated malloced string.
	use when you'll manualy use loop to set the string.
	returns NULL if allocation failed or length is below zero.
*/
char	*new_ystrm(int length)
{
	char	*str;

	if (length < 0)
		return (NULL);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	return (str);
}