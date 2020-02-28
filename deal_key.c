/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:55:19 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/29 00:19:01 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *env)
{
	static	t_ivec2 offset;

	if (key == 53)
		exit_env((t_env*)env);
	if (key == 84)
		((t_env*)env)->transf = 2;
	if (key == 83)
		((t_env*)env)->transf = 1;
	if (key == 69)
		((t_env*)env)->zoom *= 2;
	if (key == 78 && ((t_env*)env)->zoom != 1)
		((t_env*)env)->zoom /= 2;
	if (key == 123 || key == 124)
	{
		offset.x += (key == 123) ? -10 : 10;
		((t_env*)env)->offset.x = offset.x;
	}
	if (key == 126 || key == 125)
	{
		offset.y += (key == 126) ? -10 : 10;
		((t_env*)env)->offset.y = offset.y;
	}
	if (key == 8)
		center(env, &offset);
	clear_and_draw((t_env*)env);
	return (0);
}
