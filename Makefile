# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:17:03 by lgaume            #+#    #+#              #
#    Updated: 2023/12/21 12:30:47 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft/libft.a
INC = inc/
SRC_PATH = src/
OBJ_PATH = obj/

GREEN = \033[032m
BLUE = \033[034m
YELLOW = \033[033m
RESET = \033[0m

SRC = so_long pathfinding utils map checks handling_errors points generate_window move
SRCS 	= $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC)))
OBJ 	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

all:					$(NAME)

make_all:
						@make mlx && make libft && make

clean_all:				clean
						@make mlx_clean && make libft_clean && make fclean

$(LIBFT) :
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"

$(NAME): 				$(OBJ)
						@$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
						@echo "$(GREEN)[✓] so_long compiled$(RESET)"

$(OBJ_PATH)%.o: 		$(SRC_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

clean:
						@$(RM) $(OBJ)
						@make clean -C ./libft

fclean:					clean
						@$(RM) $(NAME)
						@echo "$(YELLOW)Cleaned so_long $(RESET)"

re:						fclean all

libft:					$(LIBFT)

libft_clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"

mlx:
						@make -s -C ./mlx
						@echo "$(BLUE)[✓] MLX compiled$(RESET)"

mlx_clean:
						@make clean -C ./mlx
						@echo "$(YELLOW)Cleaned MLX$(RESET)"

.PHONY:					all clean fclean re mlx mlx_clean libft libft_clean make_all clean_all
