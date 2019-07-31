/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:30:13 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/21 22:06:25 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"


static int	ft_rgb(unsigned char r,unsigned char g,unsigned char b)
{
	unsigned char color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;

	return (*(int *)color);
}

void ft_init_vec(t_vec *v,double a, double b, double c)
{
    v->x = a;
    v->y = b;
    v->z = c;
}

void  ft_map_xy(double *x, double *y, t_init *init)
{
    *x = (((init->win_right - init->win_left) * (*x)) / WIDTH) + init->win_left;
    *y = (((init->win_up - init->win_down) * (*y)) / WIDTH) + init->win_down;
}

double ft_solveqadratique(t_ray *ray,t_sphere *sphere, double *t)
{
    double a;
    double b;
    double c;
    double d;
    t_vec  dist;


    a = ft_dot(&ray->d,&ray->d);
    dist = ft_sub(&sphere->c,&ray->o);
    c = ft_dot(&dist,&dist) - ((sphere->r) * (sphere->r));
    b = 2 * ft_dot(&ray->d,&dist);

    d = (b * b) -(4 * c * a);  
   
    if (d < 0)
       return (0);
       else
       {
           return (1);
       }
       
    double sqrtd = sqrt(d);
    double t0 = (-b + sqrtd) / 2 * a; 
    double t1 = (-b - sqrtd) / 2 * a; 
    if (t0 > 1e-6 && t0 < *t)
    {
        *t = t0;printf("%f\n",t0);
        return (1);
    }
    else if (t1 > 1e-6 && t1 < *t)
    {
        *t = t1;printf("%f\n",t1);
        return (1);
    }
    else
        return (0);
    
}
double ft_solveqadratique_cylinder(t_ray *ray,t_cylinder *cylinder, double *t)
{
    double a;
    double b;
    double c;
    double d;
    t_vec  dist;
    t_vec v;

    ft_init_vec(&v,0,2,0);
    v = ft_norm(&v);
     cylinder->r = 1.1;
     ft_init_vec(&cylinder->c,0,2,0);
   
    dist = ft_sub(&ray->o, &cylinder->c);
    a = ft_dot(&ray->d,&ray->d) - (ft_dot(&ray->d,&v) * ft_dot(&ray->d,&v));// D|D - (D|V)^2
    c = ft_dot(&dist,&dist) - (ft_dot(&dist,&v) * ft_dot(&dist,&v) ) - (cylinder->r * cylinder->r);//= X|X - (X|V)^2 - r^2
    b = 2 * (ft_dot(&ray->d,&cylinder->dist) - ( ft_dot(&ray->d,&v) * ft_dot(&ray->d,&v)));//2 * (D|X - (D|V)*(X|V))

    d = (b * b) -(4 * c * a);  
   
    if (d < 0)
       return (0);
     
       
    double sqrtd = sqrt(d);
    double t0 = (-b + sqrtd) / 2 * a; 
    double t1 = (-b - sqrtd) / 2 * a; 
    if (t0 > 1e-4 && t0 < *t)
    {
        *t = t0;//printf("%f\n",t0);
        return (1);
    }
    else if (t1 > 1e-4 && t1 < *t)
    {
        *t = t1;//printf("%f\n",t1);
        return (1);
    }
    else
        return (0);
    
}

int    ft_plan(t_ray *ray)
{
    t_vec i;
    t_vec j;
    t_vec k;

    ft_init_vec(&i,2,8,0);
    ft_init_vec(&j,6,2,0);
    k = ft_cross(&i,&j);
    k = ft_norm(&k);
    if (ft_dot(&k,&ray->d) == 0)
        return (1);
    else
    {
            return (1);
    }
        
}
int  ft_cone(t_ray *ray,t_cone *cone, double *t)
{
     double a;
    double b;
    double c;
    double d;
  
    t_vec  dist;


    dist = ft_sub(&ray->o,&cone->c);
    c = (ft_dot(&dist,&cone->v) * ft_dot(&dist,&cone->v)) - cos(0.15)* (ft_dot(&dist,&dist) * (cone->co_s * cone->co_s));
    b = 2 * ((ft_dot(&ray->d,&cone->v) * ft_dot(&dist,&cone->v)) - cos(0.15)* (ft_dot(&ray->d,&dist) * (cone->co_s * cone->co_s) ));
    a = ((ft_dot(&dist,&cone->v) * ft_dot(&dist,&cone->v)) - cos(0.15)* (cone->co_s * cone->co_s));

    d = (b * b) -(4 * c * a);  
   
    if (d < 0)
       return (0);
    //    else
    //    {
    //        return (1);
    //    }
       
    double sqrtd = sqrt(d);
    double t0 = (-b + sqrtd) / 2 * a; 
    double t1 = (-b - sqrtd) / 2 * a; 
    if (t0 > 1e-6 && t0 < *t)
    {
        *t = t0;printf("%f\n",t0);
        return (1);
    }
    else if (t1 > 1e-6 && t1 < *t)
    {
        *t = t1;printf("%f\n",t1);
        return (1);
    }
    else
        return (0);

}

void ft_init_cone(t_cone *cone)
{
   

    ft_init_vec(&(cone->c),0,0,1);
    ft_init_vec(&cone->v,0,2,1);
    cone->v = ft_sub(&cone->c,&cone->v);
    cone->v = ft_norm(&cone->v);
    cone->co_s = 9;

}
void        ft_main_4(t_init *init)
{
    t_ray ray;
    t_sphere  sphere;
    t_cylinder cylinder;
    t_cone  cone;
    t_vec v;
    t_vec u;
    double x0;
    double y0;
    int x;
    int y; 

    y = -1;
    sphere.r = 1.0;
   
//       a   = D|D - (1+k*k)*(D|V)^2
//   b/2 = D|X - (1+k*k)*(D|V)*(X|V)
//    c   = X|X - (1+k*k)*(X|V)^2
    
    ft_init_vec(&(ray.o),init->camira.x,init->camira.y,init->camira.z);
     ft_init_vec(&(sphere.c),0,0,-100);
     ft_init_cone(&cone);
      
    while (++y < WIDTH)
    {
        y0 = y;
       
        x = -1;
        double t = 1e30;
        while (++x  < WIDTH)
        {
            x0 = x;
            //ft_map_xy(&x0,&y0,init);
             x0 = (((init->win_right - init->win_left) * (x)) / WIDTH) + init->win_left;
             y0 = (((init->win_up - init->win_down) * (y)) / WIDTH) + init->win_down;
            ft_init_vec(&v,x0,y0,0);
          // printf("x = %d          xf = %f || y =  %d          xf =  %f\n", x, v.x, y, v.y);
           //usleep(1000);
            u = ft_sub(&ray.o,&v);
              
           // cylinder.dist =  ft_sub(&ray.o,&cylinder.c);
            ray.d = ft_norm(&u);
            // if (ft_solveqadratique(&ray,&sphere, &t) == 1)
            // //if (ft_plan(&ray) == 1)
            // {          
            //     init->str_img[x + WIDTH * y] = ft_rgb(247,204,76);//ft_putendl("yassine");
            // } 
            // // else
            //  else 
             if (ft_solveqadratique_cylinder(&ray,&cylinder, &t) == 1)
            {          
                init->str_img[x + WIDTH * y] = ft_rgb(2,2,254);//ft_putendl("yassine");
            } 
            //   else if (ft_cone(&ray,&cone, &t) == 1)
            // {          
            //     init->str_img[x + WIDTH * y] = ft_rgb(255,2,4);//ft_putendl("yassine");
            // } 
            
            
        }
    }
}