/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:52:58 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 17:17:00 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# define H	0
# define L	1
# define Z	2
# define J	3
# define LL	4
# define HH	5

# define ANSI_COLOR_BLACK   "\033[30m"
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_form
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				width;
	int				prec;
	int				length;
	int				field;
	int				ret;
}					t_form;

typedef	struct		s_fct
{
	char			c;
	int				(*f) (va_list ap, t_form *form);
}					t_fct;

char				*ft_getwchar(wchar_t wc);
int					ft_wcharlen(wchar_t c);
int					print_wstr(wchar_t *wc, t_form *form);
int					print_wchar(wchar_t wc, t_form *form);

char				*ft_convert_oct(unsigned long long n);
unsigned int		ft_convert_uns_oct(unsigned long long n);
int					ft_printf(char *format, ...);
int					ft_putsign(int	nb);
char				*ft_convert_hex(unsigned long long n, t_form *form);
char				*ft_convert_maj_hex(int n);
char const			*ft_convert_long_hex(long int n, int maj);

long long			signed_cast(long long val, int mod);
long long			unsigned_cast(unsigned long long val, int mod);

int					print_int(va_list ap, t_form *form);
int					print_uns_int(va_list ap, t_form *form);
int					print_hex(va_list ap, t_form *form);
int					print_char(va_list ap, t_form *form);
int					print_percent(va_list ap, t_form *form);
int					print_oct(va_list ap, t_form *form);
int					print_str(va_list ap, t_form *form);
int					print_ptr(va_list ap, t_form *form);
int					print_bin(va_list ap, t_form *form);

int					first_uns_case(t_form *form, int len, long long ival);
int					second_uns_case(t_form *form, int len, long long ival);
int					third_uns_case(t_form *form, int len, long long ival);
int					fourth_uns_case(t_form *form, int len, long long ival);
int					fifth_uns_case(t_form *form, int len, long long ival);

int					first_case(t_form *form, int len, long long ival);
int					second_case(t_form *form, int len, long long ival);
int					third_case(t_form *form, int len, long long ival);
int					fourth_case(t_form *form, int len, long long ival);
int					fifth_case(t_form *form, int len, long long ival);

int					ft_fmt(va_list ap, t_form *form);
void				init_format(t_form *form);
int					flags(char **str, t_form *form);
int					width(char **str, t_form *form);
int					precision(char **str, t_form *form);
int					length(char **str, t_form *form);
void				field(char **str, t_form *form);

int					print_width(int width, int len, int flag);
int					print_prec(int prec, int len, int type);
int					print_blank(va_list ap, int nb, int prec);

char				find_char(const char *s1, const char *s2);
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
int					int_len(long long n);
int					uns_len(unsigned long long nb);
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
void				ft_putnbr(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strrev(char *str);
void				ft_putnbr_uns(unsigned long long n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
long long			abs_val(long long nb);

#endif
