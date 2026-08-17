# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 16:10:29 by yzoullik          #+#    #+#              #
#    Updated: 2025/02/12 12:45:41 by yzoullik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h

SRC =	so_long.c\
		get_next_line.c\
		get_next_line_utils.c\
		split.c\
		pars.c\
		utils.c\
		pars_utils.c\
		render.c\
		pars_utils2.c


NAMEB = so_long_bonus
HEADERB = bonus/so_long_bonus.h

SRCB =	bonus/so_long_bonus.c\
		bonus/get_next_line_bonus.c\
		bonus/get_next_line_utils_bonus.c\
		bonus/split_bonus.c\
		bonus/pars_bonus.c\
		bonus/utils_bonus.c\
		bonus/pars_utils_bonus.c\
		bonus/render_bonus.c\
		bonus/pars_utils2_bonus.c\
		bonus/ai_bonus.c
		
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

MLX_DIR = ./minilibx-linux
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(NAME)

bonus : $(NAMEB)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	cc $(OBJ) -o $(NAME) $(MLXFLAGS)

$(NAMEB): $(OBJB)
	make -C $(MLX_DIR)
	cc $(OBJB) -o $(NAMEB) $(MLXFLAGS)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADERB)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: clean
