# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 00:17:44 by cchetana          #+#    #+#              #
#    Updated: 2022/06/11 19:00:21 by cchetana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
FRAMEWORKS	= -framework OpenGL -framework AppKit
SRCS		= srcs/*.c \
				srcs/event/*.c \
				srcs/parse/*.c \
				srcs/render/*.c \
				srcs/error/*.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= minilibx_macos/libmlx.a \
			  libft/libft.a
CFLAGS		= gcc -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	@make -C minilibx_macos/ --silent
	@make -C libft/ --silent
	$(CFLAGS) $^ -I includes $(SRCS) -o $(NAME) $(INCLUDES) $(FRAMEWORKS)
	@echo "/// ----- fdf is served ----- ///"

$(OBJS)%.o: $(SRCS)%.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

clean:
	@make -C libft/ clean --silent
	@make -C minilibx_macos/ clean --silent
	@rm -rf $(OBJS)

fclean: 
	@rm -rf $(NAME)
	@make -C libft/ fclean --silent

re: fclean all