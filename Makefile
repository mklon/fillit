#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 18:54:53 by oposhiva          #+#    #+#              #
#    Updated: 2017/01/16 18:54:54 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = main.c fit_in.c core.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I fillit.h
	gcc $(OBJ) -o $(NAME)

main:
	rm main.o
	gcc -c main.c
	gcc $(OBJ) -o $(NAME)

fit_in:
	rm fit_in.o
	gcc -c fit_in.c
	gcc $(OBJ) -o $(NAME)

core:
	rm core.o
	gcc -c core.c
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
