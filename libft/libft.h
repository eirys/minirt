/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:24:14 by etran             #+#    #+#             */
/*   Updated: 2022/03/18 16:10:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_uint128
{
	uint64_t	lsb;
	uint64_t	msb;
}				t_uint128;

typedef union u_float
{
	double		num;
	uint64_t	mem;
}				t_ufloat;

typedef struct s_float
{
	uint8_t		sign;
	int32_t		exp;
	uint64_t	frac;
	int			exp_d;
	t_uint128	frac_d;
}				t_float;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void	*content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_lstsize(t_list *lst);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *charset);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

char			**ft_split(char const *s, char c);

void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);

/* ft_atof */

double			ft_atof(const char *s);
void			ft_atof_atobin(const char *s, t_float *iflt);
void			ft_atof_atodec(const char *s, t_float *iflt);
void			ft_atof_dectobin(t_float *iflt);
void			ft_atof_dectobin_exp(t_float *iflt);
void			ft_atof_dectobin_frac(t_float *iflt);
double			ft_atof_bintof(t_float iflt);

void			uint128_bzero(t_uint128 *n);
t_uint128		uint128_leftshift(t_uint128 n, unsigned int width);
t_uint128		uint128_rightshift(t_uint128 n, unsigned int width);
t_uint128		uint128_sum(t_uint128 a, t_uint128 b);
t_uint128		uint128_tenx(t_uint128 n);
t_uint128		uint128_tendiv(t_uint128 n);

/* BONUS */

long double		ft_atold(char *s);
int				ft_ischarset(char c, char *charset);
int				ft_isdouble(char *s);
int				ft_isending(char *s, char *end);
int				ft_strcmp(char *s1, char *s2);

#endif
