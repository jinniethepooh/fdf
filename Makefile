# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 00:17:44 by cchetana          #+#    #+#              #
#    Updated: 2022/06/03 23:44:52 by cchetana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
FRAMEWORKS	= -framework OpenGL -framework AppKit
SRCS		= srcs/*.c
INCLUDES	= minilibx_macos/libmlx.a \
			  libft/libft.a
CFLAGS		= -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	@make -C minilibx_macos/
	@make -C libft/
	@gcc -I includes $(SRCS) -o $(NAME) $(INCLUDES) $(FRAMEWORKS) -g
	@echo "/// ----- fdf is served ----- ///"

fclean: 
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all