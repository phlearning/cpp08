# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 11:55:46 by pvong             #+#    #+#              #
#    Updated: 2023/12/08 12:02:25 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = span

# Compilation 
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Headers

INC_DIR = include
INC = -I $(INC_DIR)
HEADERS = $(wildcard $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.tpp)


# Build

SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp \
	  Span.cpp

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CXX) $(INC) $(CXXFLAGS) -o $@ $^

show: CXXFLAGS += -DSHOWMSG=1
show: clean $(NAME) run

noshow: CXXFLAGS += -DSHOWMSG=0
noshow: clean $(NAME) run

run: $(NAME)
	./$(NAME)
	

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re