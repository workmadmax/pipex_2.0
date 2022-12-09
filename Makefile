# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 09:11:12 by mdouglas          #+#    #+#              #
#    Updated: 2022/12/09 10:32:01 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 	pipex

CC					= 	gcc
RM					= 	rm -f
CFLAGS				= 	-Wall -Werror -Wextra

LIBFT				= 	$(LIBFTPATH)/libft.a
LIBFTPATH			= 	./libft

SRCS				= 	srcs/child_proc.c srcs/exec_proc.c srcs/main.c \
							srcs/parent_proc.c srcs/path_utils.c srcs/pipe.c \
							srcs/handle_error.c \
						
OBJS				= 	$(SRCS:%.c=%.o)

all:					$(NAME)

$(NAME): 				$(OBJS)
						$(MAKE) -C $(LIBFTPATH)
						$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
						$(MAKE) -C $(LIBFTPATH) clean
						$(RM) $(OBJS)

fclean:					clean
						$(MAKE) -C $(LIBFTPATH) fclean
						$(RM) $(OBJS)

re:						clean all

.PHONY:					all clean fclean re
