/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:52:58 by rubemart          #+#    #+#             */
/*   Updated: 2024/04/28 10:59:02 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_v_list
{
	char				*s2;
	size_t				x[7];
	char				ac[2];
	int					be;
	int					be2;
	int					aux;
	int					aux2;
}	t_v_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *b, size_t len);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strncat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2, int bchangejoin);
char	*ft_substr(char const *s, unsigned int input, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split_limit(char const *s, char c);
char	**checkmalloc_1(char *s2, size_t *x, char c, char **pt);
int		ft_quotes(int qt, int qtd, int option);
void	init_qt(int *qt, int *qtd);
char	**error_malloc(char **pt);
char	**checkmalloc_2(char *s2, size_t *x, char **pt);
char	**f_writ_2(char *s2, char **pt, size_t *x);
char	**asg_2(char *s2, size_t *x, char c, char **pt);
char	**asg_limit(t_v_list	*v, char c);
void	matrix_count_limit(t_v_list	*v, char c);
char	**f_writ_limit(t_v_list	*v, char **pt, char c);
char	**checkmalloc_limit(t_v_list	*v, char c, char **pt);
void	ft_free_limit(char **pt);
char	**str_write_limit(t_v_list	*v, char **pt, int bol);
char	**ft_aux_limit(t_v_list	*v, char c, char **pt);
char	**str_count_limit(t_v_list	*v, char c, char **pt);
int		ft_str_isdigit(char *str);
void	limit(t_v_list	*v, int bol);

#endif