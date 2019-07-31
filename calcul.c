/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:23:43 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/15 20:14:18 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"


 t_vec    ft_sum(t_vec *a,t_vec *b)
{
    t_vec c;
    c.x = a->x + b->x;
    c.y = a->y + b->y;
    c.z = a->z + b->z;
    return (c);
}
 t_vec    ft_sub(t_vec *a,t_vec *b)
{
    t_vec c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;
    return (c);
}

 t_vec    ft_prod(t_vec *a,t_vec *b)
{
    t_vec c;
    c.x = a->x * b->x;
    c.y = a->y * b->y;
    c.z = a->z * b->z;
    return (c);
}
 t_vec    ft_cross(t_vec *a,t_vec *b)
{
    t_vec c;
    c.x = a->y * b->z - a->z * b->y;
    c.y = a->x * b->z - a->z * b->x;
    c.z = a->x * b->y - a->y * b->z;
    return (c);
}

 double    ft_dot(t_vec *a,t_vec *b)
{
    t_vec c;
    c.x = a->x * b->x;
    c.y = a->y * b->y;
    c.z = a->z * b->z;
    return (c.x + c.y + c.z);
}

 double    ft_sqrt(t_vec *a)
{
    return (sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z)  ));
}


 t_vec    ft_prod_l(t_vec *a,double l)
{
    t_vec c;
    c.x = a->x * l;
    c.y = a->y * l;
    c.z = a->z * l;
    return (c);
}

 t_vec    ft_norm(t_vec *a)
{
    t_vec c;
    c.x = a->x / ft_sqrt(a);
    c.y = a->y / ft_sqrt(a);
    c.z = a->z  / ft_sqrt(a);
    return (c);
}
