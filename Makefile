# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 16:09:03 by ietlapa-          #+#    #+#              #
#    Updated: 2024/06/06 14:10:28 by ietlapa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -Wall -Werror -Wextra
AR = ar rcs
RM = rm -fr
INCLUDE = ft_printf.h

SRC = ft_hexadecimals.c ft_printf.c ft_utils.c ft_putptr.c

OBJ = $(SRC:.c=.o) # la extension .c de los archivos de SRC se reemplaza por la .o

all: $(NAME) # FUNCION DE ENTRADA: al ejecutar make en la shell llega a esta funcion, llama a la funcion $(LIBFT)


$(NAME): $(OBJ) $(INCLUDE) # compila los outputs en una sola libreria .a, pero antes llama a la funcion %.o, porque OBJ son archivos .o
	$(AR) $(NAME) $(OBJ)

%.o: %.c # compila los .c y saca el output .o de cada uno
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re