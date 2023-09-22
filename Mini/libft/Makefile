# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 12:29:25 by jovieira          #+#    #+#              #
#    Updated: 2023/08/15 12:34:38 by jovieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
OBJ_DIR := ./obj
SRC_DIR := ./src
INCLUDE := -I ./

SRC= ft_atoi.c\
	 ft_strlen.c\
	 ft_putstr_fd.c\
	 ft_putchar_fd.c\
	 ft_putnbr_fd.c\
	 ft_strlcpy.c\
	 ft_strlcat.c\
	 ft_appendchar.c\

SRC			:= $(addprefix $(SRC_DIR)/,$(SRC))

OBJ_REG		:= $(notdir $(SRC:%.c=%.o))

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_REG))

CFLAGS	:= -Wall -Wextra -Werror 
# CFLAGS	+= -fsanitize=address -g
HEADER	:= libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -crs $(NAME) $(OBJ)
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(CFLAGS) $(INCLUDE) -o $@ -c $<
	
$(OBJ_DIR):
	mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re