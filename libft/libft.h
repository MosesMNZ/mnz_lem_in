/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:47:58 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/18 08:00:38 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "./get_next_line.h"

typedef unsigned char	t_byte;
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_box
{
	int					pound_flag;
	int					zero_flag;
	int					minus_flag;
	int					space_flag;
	int					plus_flag;
	int					field_width;
	int					precision;
	int					len_modifier;
	int					len_value;
	char				specifier;
}						t_box;

/*
** extern variables
*/

extern const char		*g_len_mod[];
extern const char		*g_specifier;
extern const char		*g_flags;

size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *s1, const char *s2, size_t len);
char					*ft_strstr(const char *s1, const char *s2);
int						ft_isspace(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strdup(const char *s);
void					ft_strclr(char *s);
char					*ft_strnew(size_t size);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,\
		char (*f)(unsigned int, char));
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst,\
		const void *src, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					ft_strdel(char **as);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,\
		unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
size_t					ft_strlcat(char *dst,\
		const char *src, size_t dstsize);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
size_t					ft_strlenc(const char *s, char c);
int						get_next_line(const int fd, char **line);
int						ft_abs(int n);
int						ft_word_count(char const *str, char c);
t_box					*box_init();
char					*ft_getz(char *num);
intmax_t				ft_big_atoi(const char *str);
void					ft_putstr_color(char *str, int color);
char					*ft_start_strstr(const char *big, const char *little);
int						matches_any_char(const char *string,\
		char char_to_match);
int						matches_any_array(const char **str,\
		const char *to_match, t_box *box);
void					flags_match(const char **format, t_box *box);
void					field_width(const char **format, t_box *box);
void					precision(const char **format, t_box *box);
void					length_modifier(const char **format, t_box *box);
void					left_align_str(char *value);
char					*ft_strstick(char *prepend,\
		char *original, int index);
int						digit_counter(char *str);
void					left_align_number(char *value);
void					zero_flag_handler(char *value);
void					str_toupper(char *value);
char					*pf_strnewchar(size_t size, char any);
int						digit_count(char *value);
uintmax_t				absolute_value(intmax_t storage);
char					*d_i_precision_handler(t_box *box,\
		char **value, intmax_t storage);
char					*d_i_flag_handler(t_box *box,\
		char *value, intmax_t storage);
char					*d_i_space_plus_handler(t_box *box,\
		char *value, intmax_t storage);
char					*d_i_negative_handler(char *value, intmax_t storage);
void					d_i_zero_flag_handler(t_box *box, char *value);
char					*d_i_printer(char *value,\
		t_box *box, va_list *param_list);
intmax_t				d_i_type_mod(t_box *box, intmax_t storage);
intmax_t				oux_type_mod(t_box *box, uintmax_t storage);
char					*str_field_width_handler(t_box *box, char *value);
char					*field_width_handler(t_box *box, char *value);
void					precision_handler(t_box *box, char **value);
char					*flag_handler(t_box *box,\
		char *value, intmax_t storage);
char					*ox_flag_handler(t_box *box, char *value);
char					*x_printer(char *value,\
		t_box *box, va_list *param_list);
char					*o_precision_handler(t_box *box, char **value);
char					*o_pound_handler(char *value,\
		t_box *box, uintmax_t ustorage);
char					*o_printer(char *value,\
		t_box *box, va_list *param_list);
char					*str_printer(t_box *box,\
		va_list *param_list, char *value);
char					*char_field_width_handler(t_box *box, char *value);
char					*c_printer(t_box *box,\
		va_list *param_list, char *v, int *l);
char					*u_printer(t_box *box,\
		va_list *param_list, char *value);
char					*p_printer(char *value,\
		t_box *box, va_list *param_list);
char					*percent_printer(char *value, t_box *box);
void					specifier_update(t_box *box);
int						print_spec(t_box *box, va_list *param_list);
int						move_past_specifier(const char **format,\
		t_box *box, int *len_value);
char					*d_i_negative_handler(char *value, intmax_t storage);
#endif
