/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:29:49 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/04 15:23:17 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

char	**make_map(size_t map_size)
{
	char	**map;
	size_t	i;

	if (!(map = ft_memalloc(sizeof(char *) * map_size)))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
		{
			ft_free_2d_array((void ***)&map, i);
			return (NULL);
		}
		ft_memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

void	print_map(char **map, size_t map_size)
{
	size_t i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

static size_t piece_count(char **pieces)
{
	int i;

	i = 0;
	while (*pieces++)
		i++;
	return (i);
}

static size_t get_map_size(char **pieces)
{
	int i;
	int j;
	int k;
	int count;
	size_t size;

	i = 0;
	count = piece_count(pieces);
	size = 0;
	j = 1;
	k = 0;
	while (i < count)
	{
		if (k < j)
		{
			k++;
			i++;
		}
		else
		{
			size += 2;
			k = 0;
			j += 2;
		}
	}
	size += 2;
	return (size);
}

int		main(int argc, char **argv)
{
	char	*input;
	char	**pieces;
	char 	**map;
	size_t	map_size;
	int		solution_found;

    if(argc == 2)
    {
	    if(!(input = read_input(argv[1])))
		{
			ft_putstr("error\n");
			return (2); //2 refers to a file error
		}
        if(!check_input(input))
		{
			ft_putstr("error\n");
			return (2); //2 refers to a file error
		}
		if(!(pieces = tetri_split(input)))
			return (1);
		solution_found = 0;
		map_size = get_map_size(pieces) - 1;
		printf("Piece count: %d\n", (int)piece_count(pieces));
		while (!solution_found)
		{
			map_size++;
			printf("Map size: %d\n", (int)map_size);
			if (!(map = make_map(map_size)))
				return (1); //1 will refer to a memory allocation failure
			solution_found = loop_through_candidates(map, map_size, pieces, 'A');
			if (!solution_found)
			{
				print_map(map, map_size);
				ft_free_2d_array((void ***)&map, map_size);
			}
		}
		ft_free_2d_array((void ***)&pieces, piece_count(pieces));
		print_map(map, map_size);
		ft_free_2d_array((void ***)&map, map_size);
	}
	else
		ft_putstr("error\n");
	return (0);
}
