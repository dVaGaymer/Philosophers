# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 01:42:35 by alopez-g          #+#    #+#              #
#    Updated: 2022/11/17 18:56:31 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

#----- HEADER -----
H_DIR	=	include
H		=	$(wildcard $(H_DIR)/*.h)
H_NODIR	=	$(notdir $(H))

#----- SRC ----
SRC_DIR	=	src
SRC		=	$(wildcard $(SRC_DIR)/*.c)
SRC		+=	$(wildcard $(SRC_DIR)/**/*.c)

#----- OBJ -----
OBJ_DIR	=	obj
OBJ		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

#----- LIBS -----
	#---- LIBFT -----
LIBFT_NAME	=	libft.a
LIBFT_DIR	=	src/lib/libft
LIBFT_H_DIR	=	$(LIBFT_DIR)/include
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)

#----- FLAGS -----
CC			=	gcc
H_FLAGS		=	-I$(H_DIR) -I$(LIBFT_H_DIR)
C_FLAGS		=	-c -Wall -Wextra -Werror
LIB_FLAGS	=	-L$(LIBFT_DIR) -lft

#----- RULES
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(sort $(dir $(OBJ)))

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN) Compilation Successfull! $(NC)"
	@echo "$(YELLOW) Linking... $(NC)"
	@$(CC) $(LIB_FLAGS) $(OBJ) -o $@
	@echo "$(GREEN) Ready! $(NC)"

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(RED) Objects removed $(NC)"

re: fclean all

#----- IMPICIT RULES -----
$(addprefix $(OBJ_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.c) $(H)
	$(CC) $(C_FLAGS) $< -o $@
.PHONY: clean fclean re all

#----- UTILS -----
RED				= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 				= \033[0m
