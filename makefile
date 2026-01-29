# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 14:17:07 by adjelili          #+#    #+#              #
#    Updated: 2026/01/29 14:37:52 by adjelili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MINI_LIB_PATH = minilibx_linux
CC = cc
CFLAGS = -Wall -Werror -Wextra
GET_NEXT_LINE_PATH = get_next_line
SRC = main.c \
      main2.c \
	  map.c \
	  utils.c \
	  parse.c \
	  $(GET_NEXT_LINE_PATH)/get_next_line.c \
	  $(GET_NEXT_LINE_PATH)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) -I$(GET_NEXT_LINE_PATH) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -L$(MINI_LIB_PATH) -lmlx -lXext -lX11 -lz -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iget_next_line -c $< -o $@	
#	$(CC) $(CFLAGS) -Iminilibx_linux -O3 -c $< -o $@
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
