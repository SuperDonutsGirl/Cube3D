/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:30:16 by pamartin          #+#    #+#             */
/*   Updated: 2022/11/14 10:17:42 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int					ft_abs(float x);

char				**ft_realloc_one(char **old, int len, char *new_line);

char				*realloc_set(char *line, int new_len, char charset);

int					*ft_realloc_int(int *tab, int len_tab, int add_len);

int					ft_intlen(int nb);

char				*ft_cpy(char *dest, char *src);

char				*ft_strcpy(char *dest, char *src);

char				*ft_strcpy_complete(char *dest, char *src,
						char charset, int len);

int					ft_strfchr(char *str, char c);

void				*ft_free_split(char **split);

void				*ft_clear_split(char **split);

int					ft_isprint(int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					ft_isascii(int c);

int					ft_atoi(const char *str);

unsigned long int	ft_long_atoi(const char *str);

size_t				ft_strlen(const char *s);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strchr(char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

void				*ft_memset(void *b, int c, size_t len);

char				*ft_strnstr(const char *h, const char *n, size_t len);

char				*ft_strstr(const char *haystack, const char *needle);

int					ft_strpstr(const char *haystack, const char *needle);

int					ft_strqstr(const char *haystack, const char *needle);

void				ft_bzero(void *s, size_t n);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strjoin_space(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char*));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

char				**ft_split(char const *s, char c);

char				**ft_split_charset(char *str, char *charset);

void				ft_putnbr_fd(int n, int fd);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_calloc(size_t count, size_t size);

char				*ft_itoa(int n);

void				*ft_memmove(void *dst, const void *src, size_t len);

char				*ft_strlcpy(char *dst, const char *src, int dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

int					ft_cmp(char *s1, char *s2);

#endif
