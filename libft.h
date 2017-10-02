/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:31:58 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/02 12:09:44 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "fillit.h"

void				ft_bzero(void *s, size_t n);
void				ft_free_2d_array(void ***array, size_t size);
t_list				*ft_lst_swap(t_list **lst_start, int fi, int si);
size_t				ft_lstlen(t_list *item);
void				*ft_memalloc(size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, char const *src, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strlen(char const *s);
void				ft_swap(int *a, int *b);

#endif