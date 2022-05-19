NAME = convert

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

SRC_FILES =  ../main.cpp BaseType.cpp CharType.cpp IntType.cpp \
				DoubleType.cpp FloatType.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all : $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC_DIR)*
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<
	@echo updated $@

$(NAME) : obj $(OBJ)
	@echo ".o files updated!...linking..."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) executable compiled!"

obj:
	@mkdir -p $(OBJ_DIR)

clean :
	cd $(OBJ_DIR) && rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all