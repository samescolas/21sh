/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:24:45 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/06 10:34:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define DEFAULT "\x1B[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_intmin(int a, int b);
int					ft_intmax(int a, int b);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_countwords(const char *s, char c);
int					ft_exp(int base, int power);
int					ft_isalnum(int n);
int					ft_isalpha(int n);
int					ft_isascii(int n);
int					ft_isdigit(int n);
int					ft_isprime(int n);
int					ft_isprint(int n);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new_node);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_numlen(int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_padnbr(int n, int offset, char *color);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_padstr(const char *s, int offset, char *color);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
int					ft_sqrt(int n);
void				ft_strarrmap(char **arr, char *(*f)(char *));
void				ft_strarrdel(char ***arr);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcount(char *str, char c);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strfind(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				ft_tolower(char c);
char				ft_toupper(char c);

#endif
