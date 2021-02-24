# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 09:41:48 by sdummett          #+#    #+#              #
#    Updated: 2021/02/24 11:02:21 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = ft_main.c ft_util.c ft_op.c

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

${NAME}: all

clean:
		${RM}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.SILENT: all clean fclean re
