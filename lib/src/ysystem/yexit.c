/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:24:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 16:37:46 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	yexit(int status)
{
	exit(status);
}

void	yerror(char *str)
{
	write(2, str, ystrlen(str));
	exit(1);
}
