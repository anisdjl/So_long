# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 14:17:07 by adjelili          #+#    #+#              #
#    Updated: 2026/02/04 12:15:23 by adjelili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MINI_LIB_PATH = minilibx_linux
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
GET_NEXT_LINE_PATH = get_next_line
SRC = main.c \
      parse2.c \
	  parse3.c \
	  utils.c \
	  parse.c \
	  $(GET_NEXT_LINE_PATH)/get_next_line.c \
	  $(GET_NEXT_LINE_PATH)/get_next_line_utils.c \
	  init_data.c \
	  itoa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) -L$(MINI_LIB_PATH) -lmlx -lXext -lX11 -lz -lm -I$(GET_NEXT_LINE_PATH) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -L$(MINI_LIB_PATH) -lmlx -lXext -lX11 -lz -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx_linux -O3 -Iget_next_line -c $< -o $@	
#	$(CC) $(CFLAGS) -Iminilibx_linux -O3 -c $< -o $@
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
