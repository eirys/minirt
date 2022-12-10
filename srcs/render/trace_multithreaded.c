/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_multithreaded.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:12:33 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/07 13:21:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	computation(t_datas *datas, int px[2])
{
	datas->ray = compute_ray(datas->win.sc.c.o, compute_vec(&datas->win, \
		px, datas->m));
	datas->intersection.inter = INFINI;
	if (find_object(&datas->win, datas->ray, &datas->o, &datas->intersection))
	{
		img_put_pix(&datas->win, px[0], px[1], phong_model(datas->ray, \
			datas->o, &datas->intersection, datas->win.sc));
	}
}

static void	*trace_th(void *args)
{
	t_datas	datas;
	int		px[2];

	datas = *(t_datas *)args;
	datas.m = generate_matrix(datas.win.sc.c.o, datas.win.sc.c.vec);
	pthread_mutex_lock(datas.px_mtx);
	while (datas.px[1] < datas.win.height)
	{
		px[0] = datas.px[0];
		px[1] = datas.px[1];
		datas.px[0]++;
		if (!(datas.px[0] < datas.win.width))
		{
			datas.px[0] = 0;
			datas.px[1]++;
		}
		pthread_mutex_unlock(datas.px_mtx);
		computation(&datas, px);
		pthread_mutex_lock(datas.px_mtx);
	}
	pthread_mutex_unlock(datas.px_mtx);
	return (NULL);
}

static void	init_multithreading(t_multith *multith, t_window *win)
{
	int	i;

	memset(multith, 0, sizeof(t_multith));
	pthread_mutex_init(&multith->px_mtx, NULL);
	multith->px = malloc(sizeof(int) * 2);
	if (multith->px == NULL)
		cleanup_exit(win);
	multith->px[0] = 0;
	multith->px[1] = 0;
	i = 0;
	while (i < NUM_THREADS)
	{
		multith->datas[i].px = multith->px;
		multith->datas[i].px_mtx = &multith->px_mtx;
		multith->datas[i].win = *win;
		multith->datas[i].angle = win->angle;
		multith->datas[i].ratio = win->ratio;
		i++;
	}
}

void	trace_multithreaded(t_window *win)
{
	int				i;
	t_multith		multith;

	init_multithreading(&multith, win);
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&multith.th[i], NULL, &trace_th, &multith.datas[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(multith.th[i], NULL);
		i++;
	}
	free(multith.px);
	pthread_mutex_destroy(&multith.px_mtx);
}
