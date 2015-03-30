# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:52:14 by mchoong           #+#    #+#              #
#    Updated: 2015/03/30 19:31:07 by mchoong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computorv1
COMPILER = g++ -Wall -Wextra -Werror -std=c++11 -g
SRC = main.cpp
SRC += Lexer.cpp
SRC += Token.cpp
SRC += Term.cpp
SRC += LexicalException.cpp
SRC += SyntaxException.cpp
SRC += GeneralException.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(COMPILER) $(IFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
