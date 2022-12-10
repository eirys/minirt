# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 14:17:28 by myhuong           #+#    #+#              #
#    Updated: 2022/03/15 16:34:41 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_putendl_fd.c \
		ft_strrchr.c \
		ft_putstr_fd.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_putnbr_fd.c \
		ft_strlcat.c \
		ft_split.c \
		ft_itoa.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_putchar_fd.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_atof/ft_atof.c \
		ft_atof/ft_atof_atobin.c \
		ft_atof/ft_atof_atodec.c \
		ft_atof/ft_atof_bintof.c \
		ft_atof/ft_atof_dectobin_exp.c \
		ft_atof/ft_atof_dectobin_frac.c \
		ft_atof/ft_atof_uint128.c \
		ft_atof/ft_atof_uint128_2.c

SRCS_B	= ft_lstdelone.c \
		ft_lstsize.c \
		ft_lstnew.c \
		ft_lstclear.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstlast.c

# MY BONUS
BONUS_F = ft_ischarset \
		  ft_atold \
		  ft_strcmp \
		  ft_isending \
		  ft_isdouble
SRCS += $(addsuffix _bonus.c, ${BONUS_F})

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(OBJS) $(SRCS_B:.c=.o)
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
RM	= rm -f

all:	$(NAME)
%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)
bonus: $(OBJS_B)
		ar -rcs $(NAME) $(OBJS_B)
clean:
		$(RM) $(OBJS_B)
fclean: clean
		$(RM) $(NAME)
re:		fclean all

.PHONY:		all clean fclean re
