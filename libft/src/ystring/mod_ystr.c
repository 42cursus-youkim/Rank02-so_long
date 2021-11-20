/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_ystr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:42:56 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 19:50:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//same as strcat
int	ystr_cat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (i);
}

/*	colorize given string. memory safe!
	(frees given string then reallocates with colorized one)
	usage: ystrcolor(&str, RED)
*/
void	ystr_color(char **pstr, char *color)
{
	char	*temp;

	temp = new_ystrjoin((char *[]){color, *pstr, END, 0});
	free(*pstr);
	*pstr = temp;
}
