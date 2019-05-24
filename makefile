# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 16:17:33 by vdauverg          #+#    #+#              #
#    Updated: 2019/05/07 16:17:36 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = *.c
O_FILES = *.o
FLAGS = -Wall -Wextra -Werror


all:
	gcc $(FLAGS) -c $(C_FILES) -I fillit.h

clean:
	rm $(O_FILES)

fclean: clean


re: fclean all
