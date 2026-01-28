NAME = a.out

SRCS = main.cpp \
	   ClapTrap.cpp \
	   ScavTrap.cpp \
	   FragTrap.cpp \
	   DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = c++
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all