/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:40:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/27 21:53:00 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_env *env)
{
	t_point p1;
	t_point	p2;
	int		i;

	p1 = (t_point){0, 0, 0, 0};
	p2 = (t_point){0, 0, 0, 0};
	i = 0;
	while (i < env->map->size)
	{
		assert(env->map->content != NULL);
		p1.x = env->map->content[i].x;
		p1.y = env->map->content[i].y;
		p1.z = env->map->content[i].z;
		p1.color = env->map->content[i].color;
		ft_transform(&p1, env);
		//ft_putstr("Or here\n");
	//	printf("-->%f\t%f\n", p1.x, p1.y);
		if ((i + 1) % env->map->cols)
		{
		p2.x = env->map->content[i + 1].x;
		p2.y = env->map->content[i + 1].y;
		p2.z = env->map->content[i + 1].z;
		p2.color = env->map->content[i + 1].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		if ((i + env->map->cols) < env->map->size)
		{
			p2.x = env->map->content[i+ env->map->cols].x;
			p2.y = env->map->content[i+ env->map->cols].y;
			p2.z = env->map->content[i+ env->map->cols].z;
			p2.color = env->map->content[i+ env->map->cols].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		i++;
	}
}
