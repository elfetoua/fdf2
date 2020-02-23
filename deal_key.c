/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:55:19 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/23 21:55:45 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *env1)
{
	t_env	*env;

    env = (t_env*)env1;
    static t_ivec2 offset;
    if (key == 53)
		exit(0);
	if (key == 84)
		env->transf = 2;
	if (key == 69)
			env->zoom *= 2;
	if (key == 78)
		env->zoom /= 2;
	if (key == 123)
		{
			offset.x -= 10;
			env->offset.x = offset.x;
		}
			
	if (key == 124)
		{
			offset.x += 10;
			env->offset.x = offset.x;
		}
	if (key == 126)
		{
			offset.y -= 10;
			env->offset.y = offset.y;
		}
			
	if (key == 125)
		{
			offset.y += 10;
			env->offset.y = offset.y;
		}
	if (key == 83)
		env->transf = 1;
	if (key == 69)
			env->zoom *= 2;
	if (key == 78)
		env->zoom /= 2;
	mlx_clear_window(env->con_ptr, env->win->win_ptr);
	ft_draw_map(env->map, env);
	return (key);
}   