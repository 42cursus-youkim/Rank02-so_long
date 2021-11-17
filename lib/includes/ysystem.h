/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:14 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 15:36:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSYSTEM_H
# define YSYSTEM_H

# include <unistd.h>
# include "ystring.h"

// ===== @Functions =====
// < yexit.c >

void		yexit(int status);
void		yerror(int status, char *str);

#endif