/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:40:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/23 21:43:15 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_map *map, t_env *env)
{
	t_point	p1;
	t_point	p2;
	int		i;

	i = 0;
	while (i < map->size - 1)
	{
			ft_putstr("Fucked up here\n");
		p1 = map->content[i];
		ft_putstr("Not here\n");
		ft_transform(&p1, env);
		ft_putstr("Or here\n");
		printf("-->%f\t%f\n", p1.x, p1.y);
		if ((i + 1) % map->cols)
		{
			p2 = map->content[i + 1];
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		if ((i + map->cols) < map->size)
		{
			p2 = map->content[i + map->cols];
			ft_transform(&p2, env);
			drawline(env, p1, p2);
		}
		i++;
	}
}
