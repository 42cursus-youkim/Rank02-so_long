/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:24:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 15:37:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ysystem.h"

void	yexit(int status)
{
	exit(status);
}

void	yerror(int status, char *str)
{
	write(2, str, ystrlen(str));
	exit(status);
}
