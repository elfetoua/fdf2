/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:12:52 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/29 00:18:32 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_env(t_env *env)
{
	free(env->map->content);
	free(env->map);
	exit(0);
}

void	clear_and_draw(t_env *env)
{
	mlx_clear_window((env)->con_ptr, (env)->win->win_ptr);
	ft_draw_map(env);
}

int		center(t_env *env, t_ivec2 *offset)
{
	offset->x = 0;
	offset->y += 0 ;
	env->offset.x = env->win->size.x / 2;
	env->offset.y = env->win->size.y / 2;
	return (1);
}
