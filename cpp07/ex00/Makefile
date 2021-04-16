# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adtheus <adtheus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:20:17 by adtheus           #+#    #+#              #
#    Updated: 2021/04/16 13:30:25 by adtheus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ltl_tplt_func
COMPILER = g++

SRC_DIR = .
OBJ_DIR = obj

SRC = 			main.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

CFLAG = -g3 -fsanitize=address -Wall -Wextra -Werror

all		: $(NAME)

show	:
	@echo "SRC_DIR : $(SRC_DIR)\n"
	@echo "CFLAG : $(CFLAG)\n"
	@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
	@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

## -c = definit les fichiers sources a compiler
## -o = change le nom du fichier d'output
## $@ = la cible de la regle
## $< = la premiere dependance de la regle
## $^ = les dependances de la regle

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMPILER) $(CFLAG) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(COMPILER) $(OBJ) $(CFLAG) -o $@


debug : $(NAME)
	@./$(NAME)

clean	:
	@rm -rf $(OBJ_DIR)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all
