# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 06:07:10 by vdauverg          #+#    #+#              #
#    Updated: 2019/06/09 06:22:18 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
C_FILES = fillit.c block_check.c map_check.c process_input.c read_input.c recursion.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(C_FILES) libft/libft.a -o $(NAME)
	
clean:

re: clean all