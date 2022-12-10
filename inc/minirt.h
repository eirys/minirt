/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:29:07 by etran             #+#    #+#             */
/*   Updated: 2022/06/08 16:50:23 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <float.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "minirt_structs.h"
# include "colorcodes.h"

# define BUFFER_SIZE 1024
# define X 0
# define Y 1
# define Z 2
# define R 0
# define G 1
# define B 2
# define A_ID 1
# define C_ID 2
# define L_ID 3
# define SP_ID 4
# define PL_ID 5
# define CY_ID 6
# define CO_ID 7
# define BAD_ID -1
# define INFINI 9999999999999999.f
# define CHECKERBOARD 2
# define SCALE_TEXTURE 5

int				errorfatal(t_window *win);
int				error_input(char *msg);
void			free_win(t_window *win);
void			free_scene(t_scene *sc);
void			render(t_window *win);
void			img_put_pix(t_window *win, int x, int y, int color);
int				cleanup_exit(t_window *win);

/* Parsing */
int				parse_file(t_scene *sc, int fd);
int				parsing_line(char *line, t_objs **objs);
int				check_identifier(char *line);
int				check_coefficient_format(char **line);
int				check_texture_format(char **line);
int				get_identifier(char *line);
int				check_format(char *line, int id);
int				check_coordinates_format(char **line);
int				check_vec_format(char **line);
int				check_fov_format(char **line);
int				check_brightness_format(char **line);
int				check_color_format(char **line);
int				check_ambient_light_format(char **line);
int				check_diameter_format(char **line);
int				check_height_format(char **line);
int				get_object(char *line, int id, t_objs **objs);
int				get_camera(char *line, t_objs **objs);
int				get_light(char *line, t_objs **objs);
int				get_ambient_light(char *line, t_objs **objs);
int				get_plane(char *line, t_objs **objs);
int				get_sphere(char *line, t_objs **objs);
int				get_cylinder(char *line, t_objs **objs);
int				get_cone(char *line, t_objs **objs);
void			get_coefficient(char **line, float *coefficient);
void			get_coordinates(char **line, float *coordinates);
void			get_vector(char **line, float *norm);
void			get_fov(char **line, int *fov);
void			get_color(char **line, int *color);
void			get_amb_light(char **line, float *ambient_light);
void			get_diameter(char **line, float *diameter);
void			get_height(char **line, float *height);
void			get_brightness(char **line, float *brightness);
void			get_pattern(char **line, int *pattern);
void			generate_directional_vec(t_plane *p);
int				check_duplicates(t_objs *objs);
int				count_camera(t_objs *objs);
int				count_light(t_objs *objs);
int				count_ambient_light(t_objs *objs);
int				count_object(t_objs *objs, int id);
int				store_objects(t_scene *sc, t_objs *objs);
int				store_camera(t_scene *sc, t_objs *objs);
int				store_light(t_scene *sc, t_objs *objs);
int				store_ambient_light(t_scene *sc, t_objs *objs);
int				store_sphere(t_scene *sc, t_objs *objs);
int				store_plane(t_scene *sc, t_objs *objs);
int				store_cylinder(t_scene *sc, t_objs *objs);
int				store_cone(t_scene *sc, t_objs *objs);
void			skip_whitespaces(char **line);
void			skip_int(char **line);
void			skip_float(char **line);
int				ft_isint(char **line);
int				ft_isfloat(char **line);
void			skip_identifier(char **line);
t_objs			*new_objs(void *content, int id);
void			clear_objs(t_objs **lst, void (*del)(void *));
void			add_front_objs(t_objs **alst, t_objs *new);
int				push_object(t_objs **objs, void *content, int id);

/* Computing */
t_matrix		generate_matrix(t_vec origin, t_vec v);
void			trace(t_window *win);
void			trace_multithreaded(t_window *win);
t_ray			compute_ray(t_vec origin, t_vec dir);
t_vec			compute_vec(t_window *win, int coord[2], t_matrix m);
void			pattern(t_int *i, int c[3]);
void			fill_object_tab(t_window *win, t_ray ray, t_int tab[4],
					t_objs tmp[4]);
bool			intersect_sphere(t_sphere s, t_ray r, t_int *i);
bool			intersect_plane(t_plane plane, t_ray r, t_int *i);
bool			intersect_cyl(t_cylinder cy, t_ray ray, t_int *i);
bool			intersect_cone(t_cone cone, t_ray ray, t_int *i);
bool			find_object(t_window *win, t_ray ray, t_objs *o, t_int *max);
int				phong_model(t_ray ray, t_objs o, t_int *i, t_scene sc);

/* Computing utils */
t_int			*minimal_t(t_int *inter1, t_int *inter2);
float			modulo1(float a);
void			transform(t_matrix m, t_vec *p);
bool			discriminant(float a, float b, float c, t_int racines[2]);
bool			check_plane(t_plane p, t_ray ray, t_int *t, float r2);
int				min_arrf(float *arr, int size);

/* Color utils */
unsigned int	convert_color(int c[3]);
void			color_cpy(int d[3], t_objs o);
void			sec_add_color(int d[3], int b[3]);
void			scaled_addition(int a[3], int b[3], float s);

/* t_vec utils */
t_vec			generate_vec(float a, float b, float c);
t_vec			create_vec(t_vec a, t_vec b);
t_vec			create_vec_equation(t_vec a, t_vec b);
t_vec			convert_vect(float c[3]);
t_vec			scaledvec(float a, t_vec b);
t_vec			crossprod(t_vec a, t_vec b);
float			scalar(t_vec a, t_vec b);
float			get_norm(t_vec v);
void			normalize(t_vec *v);

/* get_next_line */
int				get_next_line(int fd, char **line);
int				copy_buffer_in_line(char *buffer, char **line);
int				ft_strlen_nl_and_strcpy(char *buffer, char *src, int choice);
int				buffer_handler(char **buffer, char **line, int fd, int eof);
int				cpy_buf_in_l_or_free(char **buffer, char *tmp, int offset, \
				int choice);
char			*save_buffer(char *ptr, char *buffer);
char			*ft_strchr_or_memset(const char *str, int ch, size_t n, \
				int choice);

#endif
