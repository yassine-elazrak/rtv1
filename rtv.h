/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:12:06 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/17 09:34:28 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "libft/libft.h"

#define WIDTH 500
#define HEIGHT 500;

typedef struct s_vec
{
    double x;
    double y;
    double z;

}       t_vec;

typedef struct init
{
    void *ptr;
    void  *win;
    int   *str_img;
    void  *img;
    double win_left;
    double win_right;
    double win_up;
    double win_down;
    t_vec   camira;

}               t_init;

typedef struct s_ray
{
    t_vec  o;
    t_vec  d;
}               t_ray;

typedef struct s_sphere
{
    t_vec  c;
    double  r;
}               t_sphere;
typedef struct s_cylinder
{
    t_vec  c;
    double  r;
    t_vec dist;
}              t_cylinder;
typedef struct s_cone
{
    t_vec  c;
    t_vec v;
    double co_s;
   // double  c;
}              t_cone;




t_vec    ft_norm(t_vec *a);
 t_vec    ft_prod_l(t_vec *a,double l);
 double    ft_sqrt(t_vec *a);
 t_vec    ft_prod(t_vec *a,t_vec *b);
 t_vec    ft_sub(t_vec *a,t_vec *b);
 t_vec    ft_sum(t_vec *a,t_vec *b);
 double    ft_dot(t_vec *a,t_vec *b);
 t_vec    ft_cross(t_vec *a,t_vec *b);
 void        ft_main_4(t_init *init);
 int  ft_key(int key,t_init *init);
 void ft_init_vec(t_vec *v,double a, double b, double c);
 //int        ft_rgb(char r,char b,char g);


#endif
