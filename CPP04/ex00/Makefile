NAME = animal

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRCDIR = srcs
INCDIR = includes
OBJDIR = objs

SRCS = main.cpp \
       Animal.cpp \
       Dog.cpp \
       Cat.cpp \
       WrongAnimal.cpp \
       WrongCat.cpp

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re