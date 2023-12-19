# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:17:03 by lgaume            #+#    #+#              #
#    Updated: 2023/12/19 14:07:37 by lgaume           ###   ########.fr        #
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

SRC = so_long pathfinding utils map checks handling_errors points generate_window
SRCS 	= $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC)))
OBJ 	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

all:					$(NAME)

$(LIBFT) :
						@make -C ./libft

$(NAME): 				$(OBJ) $(LIBFT)
						@make -C ./mlx
						@$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_PATH)%.o: 		$(SRC_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
						@$(CC) $(FLAGS) -I mlx -c $< -o $@

clean:
						@$(RM) $(OBJ)
						@make clean -C ./libft

fclean:					clean
						@$(RM) $(NAME)
						@make fclean -C ./libft

re:						fclean all

s:						
						@make -s

.PHONY:					all clean fclean re s
