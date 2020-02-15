/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:25:34 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:15 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct				s_flags
{
	int						p;
	int						m;
	int						ll;
	int						tag;
	int						pre;
	int						spc;
	int						z;
	int						j;
	int						w;
	int						h;
	int						l;
	int						zero;
}							t_flags;

typedef struct				s_mltp
{
	int						x;
	int						i;
	int						j;
	int						y;
	char					*tmp;
}							t_mltp;

typedef struct				s_varo
{
	int						i;
	int						j;
	char					*p;
	char					tmp;
}							t_varo;

typedef struct				s_vardb
{
	double					d;
	long double				dd;
	char					*t;
	int						i;
	int						w;
}							t_vardb;

typedef struct				s_chralgo
{
	char					*t;
	char					*s;
	char					*tmp;
	int						b;
}							t_chralgo;

typedef struct				s_vars
{
	char					*t;
	char					*s;
	char					*tmp;
	char					*tmp2;
	int						l;
}							t_vars;

typedef	union
{
	double					d;
	struct
	{
		unsigned int		m1:32;
		unsigned int		m2:20;
		unsigned int		exponent:11;
		unsigned int		sign:1;
	}						u_field;
}							t_double;

typedef union
{
	long double				d;
	struct
	{
		unsigned int		m1:32;
		unsigned int		m2:32;
		unsigned int		exponent:15;
		unsigned int		sign:1;
	}						u_fieldd;
}							t_doublee;

typedef struct				s_addition
{
	char					*str1_1;
	char					*str2_1;
	char					*str1_2;
	char					*str2_2;
	char					*part1;
	char					*part2;
	int						length_str2;
	int						str1_point_index;
	int						str2_point_index;
}							t_addition;

typedef struct				s_multiplication
{
	char					*str1;
	char					*str2;
	int						point;
	int						str1_length;
	int						str2_length;
	char					**result;
}							t_multiplication;

typedef union				u_float_union {
	long double				the_float;
	struct
	{
		unsigned long long	mantissa : 63;
		unsigned long long	bias : 1;
		unsigned long long	exponent : 15;
		unsigned long long	sign : 1;
	}						row;
}							t_float_union;

typedef struct				s_float
{
	char					*mantissa;
	char					*exponent;
	char					*two;
	char					*result;
	t_float_union			number;
	int						i;
	int						x;
	char					*dump;
}							t_xfloat;

int							check_round(char *num, int i);
void						swap_str(char **str1, char **str2);
void						remove_zero(char **str);
void						reverse_str(char **str);
char						*addition(char *str1, char *str2);
char						*add_part_two(char *str1, char *str2, int *rest);
char						*add_part_one(char *str1, char *str2, int *rest);
char						*part_two(char *str);
char						*part_one(char *str);
void						add_zero(char **str, int i);
char						*without_point(char *str, int *point);
char						*multiplication(char *str1, char *str2);
char						*add_point(char *str, int point);
int							exponent_calc(char *str);
char						*mantissa_calc(char *str);
void						rounding(char **str, int precision);
char						*float_calc(long double f, t_flags *flag);
char						*powerr(char *number, int pow);
void						join_zeros(char **str, int i);
void						free_addition(t_addition *args);
void						lesss(int *rest, char **tmp, char **str1, int *i);
int							special_cases(t_xfloat *x, t_flags *f);
char						*ft_itoa_long(unsigned long long n);
int							calcexxpo(int *str);
void						algonor(t_chralgo *k);
int							print_b(va_list str, t_flags f);
char						*frjoin(char *c, char *s);
char						*frsetjoin(char *s, int l, char c);
char						*freejoin(char *c, char *s);
char						*freesetjoin(char c, int l, char *s);
int							print_c(va_list str, t_flags f);
int							check(const char *str, t_flags *f);
int							print_s(va_list str, t_flags f);
int							print_p(va_list str, t_flags f);
char						*to_hexa(long int n, int k, t_flags f);
int							print_d(va_list str, t_flags f);
char						*ft_iitoa(long long int n);
char						*ft_itoa_uns(unsigned long long int n);
int							print_u(va_list str, t_flags f);
int							print_o(va_list str, t_flags f);
int							print_x(va_list str, t_flags f, int k);
int							print_f(va_list str, t_flags f);
char						*add(char *s, char *str);
char						*multip(char *s, char c);
char						*power(char *str, int y);
char						*dbl(double *v);
char						*ld(long double v);
int							binary(unsigned int n, int i, int *str, int x);
char						*multp(char *s, char *str);
char						*ad(char *s, char *str, int x);
char						*addd(char *s, char *str, int x, int *k);
int							clean(char *s);
int							print_a(const char *str1, t_flags f);
int							binaire(unsigned int n, int i, int *str);
int							bbinaire(unsigned int n, int i, int *str, int x);
char						*cast(t_flags f, va_list str);
int							print_lim(char *t, t_flags f);
void						less(t_flags *f, char *t, int *i);
int							lim(char **s, int *str);
int							limi(char **s, int *str);
int							ft_printf(const char *fmt, ...);
int							print_e(va_list str, t_flags f);

#endif
