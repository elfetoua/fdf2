/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:42:59 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/27 22:10:47 by elfetoua         ###   ########.fr       */
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

void	ft_setup(t_env *env, int size)
{
	t_ivec2		win_size;

	win_size = (t_ivec2){(size > 300) ? SIZE2 : SIZE1, (size > 300) ? SIZE2 : SIZE1};
	env->con_ptr = mlx_init();
	if (env->con_ptr == NULL)
		{
			ft_putendl("init error");
			exit(0);
		}
	env->win = ft_new_win(env->con_ptr, "FDF", win_size);
	if (env->con_ptr == NULL)
		{
			ft_putendl("window error");
			exit(0);
		}
	env->zoom = 1;
	env->offset = (t_ivec2){10, 10};
}
