# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 09:11:12 by mdouglas          #+#    #+#              #
#    Updated: 2022/12/20 15:19:55 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME										= 	pipex

CC											= 	gcc
RM											= 	rm -f
CFLAGS										= 	-Wall -Werror -Wextra

LIBFT										= 	$(LIBFTPATH)/libft.a
LIBFTPATH									= 	./libft

SRCS										= 	child_proc.c exec_proc.c main.c \
													parent_proc.c path_utils.c pipe.c \
													handle_error.c \

VPATH										=	./srcs
						
OBJS										= 	$(SRCS:%.c=%.o)

all:										$(NAME)

$(NAME): 									$(OBJS)
												$(MAKE) -C $(LIBFTPATH)
												$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
												$(MAKE) -C $(LIBFTPATH) clean
												$(RM) $(OBJS)

fclean:										clean
												$(MAKE) -C $(LIBFTPATH) fclean
												$(RM) $(OBJS) $(NAME)

re:											fclean all

.PHONY:										all clean fclean re
