# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 14:17:07 by adjelili          #+#    #+#              #
#    Updated: 2026/02/11 11:45:48 by adjelili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(GET_NEXT_LINE_PATH) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)

GET_NEXT_LINE_PATH = get_next_line
BONUS_PATH = so_long_bonus/
MANDATORY_PATH = so_long_mandatory
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MINILIBX_DIR = minilibx_linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
BONUS_MAKER = .bonus

SRC_GNL = $(GET_NEXT_LINE_PATH)/get_next_line.c \
		  $(GET_NEXT_LINE_PATH)/get_next_line_utils.c

OBJ_GNL = $(SRC_GNL:.c=.o)

SRC_MANDATORY = $(MANDATORY_PATH)/main.c \
      $(MANDATORY_PATH)/parse2.c \
	  $(MANDATORY_PATH)/parse3.c \
	  $(MANDATORY_PATH)/utils.c \
	  $(MANDATORY_PATH)/parse.c \
	  $(MANDATORY_PATH)/init_data.c \
	  $(MANDATORY_PATH)/images.c \
	  $(MANDATORY_PATH)/player_move.c \
	  $(MANDATORY_PATH)/clean.c \
	  $(MANDATORY_PATH)/utils2.c \
	  $(MANDATORY_PATH)/ft_strtrim.c

SRC_BONUS = $(BONUS_PATH)main.c \
			$(BONUS_PATH)parse2.c \
			$(BONUS_PATH)parse3.c \
			$(BONUS_PATH)parse.c \
			$(BONUS_PATH)utils.c \
			$(BONUS_PATH)init_data.c \
			$(BONUS_PATH)itoa.c \
			$(BONUS_PATH)images.c \
			$(BONUS_PATH)player_move.c \
			$(BONUS_PATH)clean.c \
			$(BONUS_PATH)draw_annim.c \
			$(BONUS_PATH)utils2.c \
			$(BONUS_PATH)ft_strtrim.c

OBJ = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(PRINTF_LIB) :
	$(MAKE) -C $(PRINTF_DIR)

$(MINILIBX_LIB) :
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB) $(MINILIBX_LIB) $(OBJ_GNL)
	@rm -f $(BONUS_MAKER)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) $(MINILIBX_LIB) $(OBJ_GNL) -lXext -lX11 -lz -lm -o $(NAME)

bonus : $(BONUS_MAKER)

$(BONUS_MAKER): $(OBJ_BONUS) $(MINILIBX_LIB) $(PRINTF_LIB) $(OBJ_GNL)
	@rm -f $(NAME)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF_LIB) $(MINILIBX_LIB) $(OBJ_GNL) -lXext -lX11 -lz -lm -o $(NAME)
	@touch $(BONUS_MAKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(BONUS_MAKER)
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_GNL) $(BONUS_MAKER)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean	

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re : fclean all

.PHONY: all clean fclean re
