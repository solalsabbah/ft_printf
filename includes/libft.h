/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:52:58 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/22 15:54:32 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define COLOR_NORMAL    "\033[m"
#define COLOR_BLACK     "\033[30m"
#define COLOR_RED       "\033[31m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_WHITE     "\033[37m"
#define COLOR_RESET     "\033[0m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_fct
{
	char		c;
	int			(*f) (va_list ap, int nb, int prec, int *flags);
}			t_fct;

typedef struct	s_form
{
	char		minus;
	char		plus;
	char		space;
	char		zero;
	char		hash;
	int			width;
	int			pre;
	int			preflag;
	int			length;
	int			nul;
	int			apo;
	int			dolls;
}				t_form;



long int			ft_convert_oct(unsigned long long n);
unsigned int			ft_convert_uns_oct(unsigned long long n);
int				ft_printf(const char *restrict format, ...);
int				ft_putsign(int	nb);
char				*ft_convert_hex(unsigned int n, int maj);
char				*ft_convert_maj_hex(int n);
char const			*ft_convert_long_hex(long int n, int maj);
int				ft_width(int ival, int nb);
int				print_hex(va_list ap, int nb, int prec, int *flags);
int				print_char(va_list ap, int nb, int prec, int *flags);
int				print_percent(va_list ap, int nb, int prec, int *flags);
int				print_maj_hex(va_list ap, int nb, int prec, int *flags);
int				print_oct(va_list ap, int nb, int prec, int *flags);
int				print_int(va_list ap, int nb, int prec, int *flags);
int				print_str(va_list ap, int nb, int prec, int *flags);
int				print_ptr(va_list ap, int nb, int prec, int *flags);
int				print_bin(va_list ap, int nb, int prec, int *flags);
int				print_uns_int(va_list ap, int nb, int prec, int *flags);
int				print_percent(va_list ap, int nb, int prec, int *flags);
int				ft_fmt(const char *str, va_list ap);
int				print_width(int nb, int len, int flag);
int				print_blank(va_list ap, int nb, int prec, int *flags);
int				find_width(const char *str);
int				find_precision(const char *str);


char				*ft_strpbrk(const char *s1, const char *s2);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_strlen_int(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
int					ft_strlen2(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				count_before(char const *s);
size_t				count_after(char const *s);
size_t				int_len(long int n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_strdel(char **as);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char 				*ft_strrev(char *str);
void				ft_putnbr_uns(long int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					abs_val(int nb);

#endif
