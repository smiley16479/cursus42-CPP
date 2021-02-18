# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 12:06:29 by mli               #+#    #+#              #
#    Updated: 2020/09/11 14:21:24 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang++
CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = main.cpp

HEADER_FILES = Array.hpp

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.cpp=.o}}

all: ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS} ${HEADER_FILES}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.cpp ${HEADER_FILES}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS_PATH}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
