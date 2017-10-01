/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:36:45 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/30 18:08:08 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

typedef struct		s_list
{
	char			**shape;
	char			id;
	t_coords		*dimensions;
	struct s_list	*next;
}					t_list;

int					loop_through_condidates(char **map, size_t map_size, t_list *piece);
int					consider_candidate(char **map, size_t map_size, t_list *piece);
int					accept(char **map, size_t map_size, t_list *piece);
void				set_piece(char **map, size_t map_size, t_list *piece, t_coords *coords);
void				remove_piece(char **map, size_t map_size, t_list *piece);
t_coords			*find_first_placement(char **map, size_t map_size, t_list *piece);
int					can_place_here(char **map, size_t map_size, t_list *piece, t_coords *coords);

t_list				*copy_list_item(t_list *item);
t_list				*duplicate_list(t_list *item);

char				**make_map(size_t map_size);
void				print_map(char **map, size_t map_size);
void				free_map(char **map, size_t map_size);

#endif
