/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:55:19 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/27 23:23:41 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *env)
{
	static	t_ivec2 offset;

	if (key == 53)
		exit(0);
	if (key == 84)
		((t_env*)env)->transf = 2;
	if (key == 83)
		((t_env*)env)->transf = 1;
	if (key == 69)
		((t_env*)env)->zoom *= 2;
	if (key == 78)
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
	//(key == 8)
	mlx_clear_window(((t_env*)env)->con_ptr, ((t_env*)env)->win->win_ptr);
	ft_draw_map((t_env*)env);
	return (0);
}
