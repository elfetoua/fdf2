/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:42:59 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/23 21:03:56 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*ft_new_win(void *con_ptr, char *title, t_ivec2 size)
{
	t_win	*win;

	win = (t_win*)malloc(sizeof(t_win));
	win->con_ptr = con_ptr;
	win->win_ptr = mlx_new_window(con_ptr, size.x, size.y, title);
	win->size = size;
	win->title = title;
	return (win);
}

void	ft_setup(t_env *env)
{
	t_ivec2		win_size;

	win_size = (t_ivec2){1000, 1000};
	env->con_ptr = mlx_init();
	env->win = ft_new_win(env->con_ptr, "FDF", win_size);
	env->zoom = 1;
	env->offset = (t_ivec2){10, 10};
}
