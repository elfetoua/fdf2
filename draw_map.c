/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:40:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/25 12:57:53 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_map *map, t_env *env)
{
	t_point p1;
	t_point	p2;
	int		i;

	i = 0;
	while (i < map->size)
	{
		p1.x = map->content[i].x;
		p1.y = map->content[i].y;
		p1.z = map->content[i].z;
		p1.color = map->content[i].color;
		ft_transform(&p1, env);
		//ft_putstr("Or here\n");
	//	printf("-->%f\t%f\n", p1.x, p1.y);
		if ((i + 1) % map->cols)
		{
		p2.x = map->content[i + 1].x;
		p2.y = map->content[i + 1].y;
		p2.z = map->content[i + 1].z;
		p2.color = map->content[i + 1].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		if ((i + map->cols) < map->size)
		{
			p2.x = map->content[i+ map->cols].x;
			p2.y = map->content[i+ map->cols].y;
			p2.z = map->content[i+ map->cols].z;
			p2.color = map->content[i+ map->cols].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		i++;
	}
}
