NAME = zombie

SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = obj

SRC_FILES = main.cpp \
			newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I$(INC_DIR)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re

