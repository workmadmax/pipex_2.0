# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 09:11:12 by mdouglas          #+#    #+#              #
#    Updated: 2022/11/30 11:13:05 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
MFLAG	= ./libft/libft.a

SRCS	= srcs/child_proc.c srcs/exec.c srcs/main.c \
			srcs/parent_proc.c srcs/path_utils.c srcs/pipe.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME) $(MFLAG)

$(MFLAG):
		make -C ./libft

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MFLAG) -o $(NAME)

clean:
		make clean -C ./libft
		$(RM) $(OBJS)

fclean:
		make clean -C ./libft
		$(RM) $(OBJS)

re: clean all

.PHONY: all clean fclean re
