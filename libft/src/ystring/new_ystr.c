/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:26:06 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:38:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	copy a string. equivalent to strdup()
	use NULL TERMINATED STRING if you'r passing it implicitly!!!
*/
char	*new_ystr(const char *from)
{
	int		i;
	int		len;
	char	*str;

	len = ystrlen(from);
	str = new_ystre(len);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = from[i];
	return (str);
}

/*	create an empty null-terminated string.
	empty spaces are filled with ' ', so it can fe safely deleted.
*/
char	*new_ystre(int length)
{
	char	*str;

	if (length < 0)
		return (NULL);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (length-- > 0)
		str[length] = ' ';
	return (str);
}
