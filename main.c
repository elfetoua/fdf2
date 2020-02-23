/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:51:43 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/23 21:27:45 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hex_dec(char *hex_val)
{
	int len;
	int base;
	int dec_val;
	int i;

	len = ft_strlen(hex_val);
	base = 1;
	dec_val = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (hex_val[i] >= '0' && hex_val[i] <= '9')
			dec_val += (hex_val[i] - 48) * base;
		else if (hex_val[i] >= 'A' && hex_val[i] <= 'F')
			dec_val += (hex_val[i] - 55) * base;
		/*else if (hex_val[i] >= 'a' && hex_val[i] <= 'f')
			dec_val += (hex_val[i] - 55 - 32) * base;*/
		base = base * 16;
		i--;
	}
	return (dec_val);
}

int		check(int i, int ret, t_map *map, char *filename)
{
	if (ret < 0)
		perror(filename);
	else if (map->size == 0)
		ft_putendl("No data found.");
	else if (i < map->cols)
		ft_putendl("Found wrong line length. Exiting.");
	return (!(ret < 0 || map->size == 0 || i < map->cols));
}

int		get_map_info(t_map *map, char *filename)
{
	char	*line;
	int		ret;
	char	**split;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	split = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		i = -1;
		while (split[++i] != NULL)
			map->size++;
		if (map->rows == 0)
			map->cols = map->size;
		if (i < map->cols)
			break ;
		map->rows += 1;
		ft_strdel(&line);
		ft_bonus_freedoubledem(split);
	}
	close(fd);
	return (check(i, ret, map, filename));
}

void	fill_data(t_map *map, int index, t_ivec2 coords)
{
	map->content[index].x = (double)coords.x;
	map->content[index].y = (double)coords.y;
	map->content[index].color = WHITE;
}

void	extract_data(t_map *map, char *filename, int fd, int index)
{
	char	*line;
	char	**split;
	t_ivec2 coords;
	char	*color;

	map->content = (t_point*)ft_memalloc(sizeof(t_point) * map->size);
	fd = open(filename, O_RDONLY);
	coords.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		coords.x = 0;
		while (split[coords.x] != NULL)
		{
			index = coords.x + coords.y * map->cols;
			fill_data(map, index, coords);
			map->content[index].z = ft_atoi(split[coords.x]);
			if ((color = ft_strchr(split[coords.x], ',')))
				map->content[index].color = hex_dec(color + 2);
				coords.x++;
		}
		free(line);
		ft_bonus_freedoubledem(split);
		coords.y++;
	}
	close(fd);
}

void	env_map(t_map *map, t_env *env)
{
	register int		i;

	i = 0;
	env->map = (t_map*)ft_memalloc(sizeof(map));
	env->map->content = (t_point*)ft_memalloc(sizeof(t_point) * map->size);
	while (i < map->size)
	{
		env->map->cols = map->cols;
		env->map->rows = map->rows;
		env->map->size = map->size;
		env->map->content[i] = map->content[i];
		//printf("%f %f %d", env->map->content[i].x, env->map->content[i].y, env->map->size);
		i++;
	}
	printf("NOT here\n");
}

int		main(int ac, char **av)
{
	t_map	map;
	t_env	env;

	if (ac == 2)
	{
		ft_bzero(&map, sizeof(t_map));
		if (get_map_info(&map, av[1]) > 0)
		{
			extract_data(&map, av[1], 0, 0);
			ft_setup(&env);
			env_map(&map, &env);
			mlx_key_hook(env.win->win_ptr, deal_key, (void*)&env);
			printf("DEBUG\n");
		// ft_draw_map(&map, &env);
			mlx_loop(env.con_ptr);
		}
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <filename> [ case_size z_size ]");
	}
	return (0);
}
