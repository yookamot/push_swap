/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:32:34 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/10 19:10:58 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int i);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int i);
char				*ft_strrchr(const char *s, int i);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t num, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putendl_fd(char *str, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *newlst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newlst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
