# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anis <anis@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 14:17:07 by adjelili          #+#    #+#              #
#    Updated: 2026/02/08 22:56:56 by anis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

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
	  itoa.c \
	  images.c \
	  player_move.c \
	  clean.c \
	  draw_annim.c \
	  utils2.c
OBJ = $(SRC:.c=.o)

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MINILIBX_DIR = minilibx_linux
MINILIBX_LIB = $(MINILIBX_DIR)/mlx.a
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) §(PRINTF_LIB) $(MINILIBX_LIB) -L$(MINI_LIB_PATH) -lmlx -lXext -lX11 -lz -lm -I$(GET_NEXT_LINE_PATH) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -L$(MINI_LIB_PATH) -lmlx -lXext -lX11 -lz -lm -o $(NAME)

$(PRINTF_LIB) :
	$(MAKE) -C $(PRINTF_DIR)

$(MINILIBX_LIB) :
	$(MAKE) -C $(MINILIBX_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -Iget_next_line -c $< -o $@	
#	$(CC) $(CFLAGS) -Iminilibx_linux -O3 -c $< -o $@
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) fclean
re : fclean all

.PHONY: all clean fclean re
