NAME      = liborm.a
CXX       = g++
CXXFLAGS  = -std=c++14 -Wall -pedantic -Wextra -Werror
OBJ       = $(SRC:%.cpp=%.o)
RM        = rm -f
SRC       = src/DB/DB.cpp								\
			src/DB/DBConfiguration/DBConfiguration.cpp	\
			src/Adapter/MySql/MySqlAdapter.cpp

.PHONY:	all $(NAME) clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all