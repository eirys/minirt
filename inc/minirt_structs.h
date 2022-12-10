/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:03:36 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/07 13:03:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCTS_H
# define MINIRT_STRUCTS_H

# define NUM_THREADS 4

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_int
{
	float	inter;
	float	coef;
	t_vec	hit;
	t_vec	normal;
	int		color[3];
	int		pattern;
	int		type;
	void	*object;
}	t_int;

typedef struct s_matrix
{
	float	x[3];
	float	y[3];
	float	z[3];
	float	t[3];
}	t_matrix;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	origin;
}	t_ray;

typedef struct s_objs
{
	void			*content;
	int				id;
	struct s_objs	*next;
}	t_objs;

typedef struct s_camera
{
	t_vec	o;
	t_vec	vec;
	int		fov;
}			t_camera;

typedef struct s_light
{
	t_vec	o;
	float	brightness;
	int		color[3];
}			t_light;

typedef struct s_ambient_light
{
	float	ambient_light;
	int		color[3];
}			t_ambient_light;

typedef struct s_sphere
{
	float	radius;
	float	r2;
	float	coef;
	t_vec	center;
	int		color[3];
	int		pattern;
}			t_sphere;

typedef struct s_plane
{
	t_vec	vec;
	t_vec	o;
	int		color[3];
	float	coef;
	int		pattern;
	t_vec	u;
	t_vec	v;
}			t_plane;

typedef struct s_cylinder
{
	t_plane		p[2];
	float		radius;
	float		r2;
	t_vec		vec;
	t_vec		center;
	t_vec		edge;
	float		coef;
	int			color[3];
	int			pattern;
}			t_cylinder;

typedef struct s_cone
{
	t_plane		p;
	float		radius;
	float		height;
	float		r2;
	t_vec		vec;
	t_vec		o;
	t_vec		edge;
	float		c_theta2;
	float		coef;
	int			color[3];
	int			pattern;
}			t_cone;

typedef struct s_scene
{
	t_camera		c;
	t_light			*l;
	t_ambient_light	a;
	int				l_nb;
	t_sphere		*sp;
	int				sp_nb;
	t_plane			*pl;
	int				pl_nb;
	t_cone			*co;
	int				co_nb;
	t_cylinder		*cy;
	int				cy_nb;
}			t_scene;

typedef struct s_pic
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_pic;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_pic			pic;
	t_scene			sc;
	int				width;
	int				height;
	float			angle;
	float			ratio;
}				t_window;

typedef struct s_datas
{
	t_window		win;
	float			angle;
	float			ratio;
	t_matrix		m;
	t_ray			ray;
	pthread_mutex_t	*px_mtx;
	int				*px;
	t_objs			o;
	t_int			intersection;
}	t_datas;

typedef struct s_multith
{
	pthread_t		th[NUM_THREADS];
	t_datas			datas[NUM_THREADS];
	pthread_mutex_t	px_mtx;
	int				*px;
}	t_multith;

#endif
