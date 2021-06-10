# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/06/10 13:39:40 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= so_long.c \
			window.c \
			hooks/action_hooks.c \
			render/render.c \
			utils/error.c
SRCS 	= $(addprefix srcs/, ${SRC})
OBJS	= ${SRCS:.c=.o}
INCS	= includes
MLX		= ./mlx
NAME	= so_long
LIBC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g3 -O3

srcs/%.o: srcs/%.c ${INCS}/${NAME}.h
	${CC} ${CFLAGS} -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	@${MAKE} bonus -C ./libft
	@${MAKE} -C ${MLX}
	${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} libft/libft.a ${MLX}/libmlx.a
all: ${NAME}

bonus: all

clean:
	${MAKE} clean -C ./libft
	${MAKE} clean -C ${MLX}
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${MAKE} fclean -C ./libft
	${MAKE} clean -C ${MLX}
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re .c.o
