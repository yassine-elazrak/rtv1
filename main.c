/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:45:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/17 13:31:21 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"


void	ft_init_00(t_init *init)
{
	init->win_left  = -0.5;
    init->win_right = 0.5;
    init->win_up = 0.5;
    init->win_down = -0.5;
	init->camira.x = 0;
	init->camira.y = 0;
	init->camira.z = 1;

}

int main()
{
	int				s_l;
	int				bpp;
	int				end;
	t_init			*init;

	
	if (!(init = (t_init *)malloc(sizeof(t_init))))
		exit(0);
	ft_init_00(init);
	init->ptr = mlx_init();
	init->win = mlx_new_window(init->ptr, WIDTH,  WIDTH, "rtv1");
	init->img = mlx_new_image(init->ptr, WIDTH,  WIDTH);
	init->str_img = (int*)mlx_get_data_addr(init->img, &bpp, &s_l, &end);
	ft_main_4(init);
	mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);	
	mlx_hook(init->win,2,0,ft_key,init);
	mlx_loop(init->ptr);
	return (0);
}
