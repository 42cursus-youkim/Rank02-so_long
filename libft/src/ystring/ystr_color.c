/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystr_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:23:16 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:56:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
