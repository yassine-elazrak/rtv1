/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:38:49 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/17 00:40:53 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	ft_change(t_init *init)
{
		mlx_clear_window(init->ptr,init->win);
    	ft_bzero(init->str_img,4*500*500);	
     	ft_main_4(init);
    	mlx_put_image_to_window(init->ptr, init->win, init->img, 0,0);
}
int   ft_info_key_1(int s,t_init *lst)
{   
	if (s == 123)
	{  lst->camira.x -= 0.09;
		
	}
	else if (s == 124)
	{ lst->camira.x += 0.09;
	
	}
    else if (s == 125)
	{  lst->camira.y += 0.09;
		
	}
	else if (s == 126)
	{ lst->camira.y -= 0.09;
	
	}
    else if (s == 0)
	{ lst->camira.z -= 0.1;
	
	}
    else if (s == 1)
	{  lst->camira.z += 0.1;
		
	}
	  else
	  {
		  return (0);
	  }
	  return (1);
}


int  ft_key(int key,t_init *init)
{
		if(key == 53)
		{
			mlx_destroy_window(init->ptr,init->win);
			mlx_destroy_image(init->ptr,init->img);
			free(init);
				exit(1);
		}
			
		if ( ft_info_key_1(key,init) )
				ft_change(init);
		
		
		return 0;
}