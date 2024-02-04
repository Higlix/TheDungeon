

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = [0m
BOLD = [1m

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = src/inc
LIB_DIR = lib

SRC += $(wildcard $(SRC_DIR)/*.cpp)

OBJ += $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

LIB = lib/raylib/src/libraylib.a
CC = g++ -std=c++11
#CFLAGS = -Wall -Werror -Wextra $(INC_DIR)
CFLAGS = -I $(INC_DIR)
NAME = game

all: $(OBJ_DIR) $(LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(MAGENTA)Object directories created..."

$(LIB):
	@make -C lib/raylib/src

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) -lm -lpthread -ldl -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	@mkdir -p bin
	@mv $(NAME) bin
	@echo "$(GREEN)Compiled { $(CYAN)$(NAME) $(GREEN)}"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(CC) -c $< -o $@ $(CFLAGS) 
	@echo "$(GREEN)Compiled {$(RED) $@ $(GREEN)}"

src: clean all

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf bin
	@echo "$(YELLOW)Object directory $(RED)DELETED"

fclean: clean
	@make clean -C lib/raylib/src
	@echo "$(YELLOW)$(NAME) $(RED)DELETED"

re: fclean all

.PHONY: all clean fclean re
