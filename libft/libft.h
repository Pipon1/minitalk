/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:17:48 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/13 16:46:31 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
// base existante
int		ft_isalnum(int c);
int		ft_isprint(int c);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
char	*ft_strnstr(const char *hay, const char *need, size_t len);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
char	*ft_strrchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int		ft_isascii(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_power(int nb, int power);
void	*ft_calloc_exit(size_t count, size_t size);

// base malloc
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);

// fonction sup non-bonus
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// printf
int		ft_printf(const char *str, ...);
int		ft_findform(va_list car, const char form);
int		ft_pchar(int c);
int		ft_ppercent(void);
int		ft_printnbr(int n);
void	ft_putstr(char *s);
int		ft_pstr(char *s);
int		ft_pnbr_unsigned(unsigned int nbr);
char	*ft_unsigneditoa(unsigned int nbr);
int		ft_nbrlenght(unsigned int nbr);
int		ft_padd(unsigned long long add);
void	ft_convadd(uintptr_t add);
int		ft_addlenght(uintptr_t add);
int		ft_hexabase(unsigned int nbr, const char form);
void	ft_printhex(unsigned int nbr, const char form);
int		ft_hexsize(unsigned int nbr);

#endif
