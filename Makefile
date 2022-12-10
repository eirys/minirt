# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 15:13:04 by etran             #+#    #+#              #
#    Updated: 2022/06/11 14:52:17 by eli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === TARGETS ===

NAME = miniRT

FILES = main.c \
		main_utils.c \
		cleanup_exit.c \
		render.c \
		get_next_line.c \
		get_next_line_utils.c

P_FILES = parsing_main.c \
		  parsing_line.c \
		  check_format_1.c \
		  check_format_2.c \
		  check_format_3.c \
		  get_object_1.c \
		  get_object_2.c \
		  get_object_3.c \
		  get_object_infos_1.c \
		  get_object_infos_2.c \
		  get_object_infos_3.c \
		  check_duplicates.c \
		  store_objects_1.c \
		  store_objects_2.c \
		  parsing_utils_1.c \
		  parsing_utils_2.c

R_FILES = utils.c \
		  intersections_1.c \
		  intersections_2.c \
		  intersections_3.c \
		  matrix.c \
		  find_object.c \
		  find_object_utils.c \
		  color_utils.c \
		  vec_basic.c \
		  vec_utils.c \
		  phong_model.c \
		  checkerboard.c \
		  compute_ray.c \
		  trace_multithreaded.c

SRCS = $(addprefix srcs/, $(FILES)\
			$(addprefix parsing/, $(P_FILES))\
			$(addprefix multithreading/, $(M_FILES))\
			$(addprefix render/, $(R_FILES)))

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

ifdef bonus
	CFLAGS +=-D BONUS=1
else
	CFLAGS +=-D BONUS=0
endif

CFLAGS +=-I./inc -I./minilibx -I./libft

ifdef debug
	CFLAGS +=-g
endif
ifdef segfault
	CFLAGS +=-fsanitize=address
endif

LIBFT = libft/libft.a
MLX = minilibx/libmlx_Linux.a
LIBRARIES = $(LIBFT) $(MLX) -lm -lXext -lX11

# ==== RULES ====

all: $(NAME)

bonus:
	make bonus=1

$(MLX):
	make -C minilibx
$(LIBFT):
	make -C libft

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)

%.o: srcs/%.c inc/*.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C minilibx clean
	make -C libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Avoid recompiling all libraries
nclean:
	rm -f $(OBJS)
	rm -f $(NAME)

regen: nclean all

.PHONY: all bonus norm clean fclean re
