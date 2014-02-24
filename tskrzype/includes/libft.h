/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:18:36 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 15:09:50 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1024

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
char	*ft_strcpy(char *s1, char const *s2);
char	*ft_strncpy(char *s1, char const *s2, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
int		ft_strlen(const char *s);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	ft_putendl(char const *s);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
char	**ft_strsplit(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *, unsigned int start, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_sctrclr(char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_striter(char *s, void(*f)(char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strtrim(char const *s);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strstr(const char *s1, const char *s2);
void	ft_strclr(char *s);
int		get_next_line(int const fd, char **line);
#endif /* !LIBFT_H */
