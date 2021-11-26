/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:42:56 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 15:25:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	looks like strjoin but is memory safe. returns: length of joined string
	usage: ystr_append(&str, STRING)
*/
int	ystr_append(char **pstr, char *src)
{
	char	*temp;

	temp = new_ystrjoin((char *[]){*pstr, src, NULL});
	del_ystr(*pstr);
	*pstr = temp;
	return (ystrlen(*pstr));
}

/*	colorize given string. memory safe!
	(frees given string then reallocates with colorized one)
	usage: ystr_color(&str, RED)
*/
void	ystr_color(char **pstr, char *color)
{
	char	*temp;

	temp = new_ystrjoin((char *[]){color, *pstr, END, 0});
	free(*pstr);
	*pstr = temp;
}

//	replace given NEW string with OLD string. memory safe!
void	ystr_replace(char **pstr, char *new_str)
{
	char	*temp;

	temp = new_str;
	del_ystr(*pstr);
	*pstr = temp;
}
