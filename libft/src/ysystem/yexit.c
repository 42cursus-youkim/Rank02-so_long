/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:24:21 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:22:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	yexit(int status)
{
	exit(status);
}

void	yerror(char *err)
{
	write(2, RED, 6);
	write(2, "error:\n  ", 9);
	write(2, err, ystrlen(err));
	write(2, END, 5);
	exit(1);
}
