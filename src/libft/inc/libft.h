/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

# include "get_next_line.h"
//# include "ft_printf.h"
//# include "ft_ls.h"

typedef unsigned char	t_byte;

// data structure nodes
typedef struct		s_node
{
	void			*data;
	size_t			d_size;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlnode
{
	void			*data;
	size_t			d_size;
	struct s_dlnode	*next;
	struct s_dlnode	*prev;
}					t_dlnode;

typedef struct		s_bnode
{
	void			*data;
	size_t			d_size;
	struct s_bnode	*left;
	struct s_bnode	*right;
}					t_bnode;

typedef struct		s_nbnode
{
	int				num;
	struct s_nbnode	*left;
	struct s_nbnode	*right;
}					tn_bnode;

typedef struct		s_snode
{
	void			*data;
	size_t			d_size;
	struct s_snode	*prev;
}					t_snode;

// data structures
typedef struct		s_lst
{
	void			*head;
	void			*tail;
	size_t			size;
}					t_lst;

typedef struct		s_btree
{
	void			*root;
	void			*left;
	void			*right;
}					t_tree;

typedef struct		s_stack
{
	struct s_snode	*top;
	size_t			size;
}					t_stack;

// memptrs
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);
void				*ft_memset(void *p, int c, size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *p, size_t size);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *p, int c, size_t n);
void				*ft_memrchr(const void *p, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

//	convert
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_hextoa(int n, size_t prec); /* need */
int					uctoutf8(const char *dest, wchar_t ch);
int					ft_hextoi(const char *hex);

//	identifiers
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
int					ft_ishex(int c);
int					ft_isemoji(int c); /* need */

//	strings
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *small);
char				*ft_strnstr(const char *big, const char *small, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrev(const char *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strinsrt(const char *dst, size_t n, const char *src);

//	prints
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_print_bits(unsigned char byte);
void				ft_putnbrnl(int n);
void				ft_puthex(int n); /* need */
void				ft_puthexnl(int n); /* need */
void				set_color(int c);

//	linkedlst
t_node				*ft_lstnew(void const *data, size_t d_size);
void				ft_lstdel(t_node **head, void (*bzero)(void *, size_t));
void				ft_lstadd(t_node **head, t_node *new);
void				ft_lstiter(t_node *head, void (*f)(t_node *node));
t_node				*ft_lstmap(t_node *head, t_node *(*f)(t_node *node));
void				ft_lstadd_back(t_node **head, t_node *new);
size_t				ft_lstlen(t_node *head);
t_node				*ft_addnodeback(t_node *tail, t_node *new); /* need */

// binarytree
t_bnode				*bt_new(void const *data, size_t d_size);
t_bnode				*bt_lookup(t_bnode *tree, void const *data, size_t d_size);
t_bnode				*bt_insert(t_bnode *tree, void const *data, size_t d_size);
tn_bnode			*btn_new(const int n);
int					btn_lookup(tn_bnode *tree, const int n);
tn_bnode			*btn_insert(tn_bnode *tree, const int n);

// stack
t_snode				*snode_new(void const *data, size_t d_size);
t_snode				*stack_push(t_snode *top, t_snode *new);
t_snode				*stack_pop(t_snode *top);
t_snode				*stack_lookup(t_snode *top, t_snode *node);
int					snode_del(t_snode *node);

//	misc
int					ft_digitnum(int n, int base);

#endif
