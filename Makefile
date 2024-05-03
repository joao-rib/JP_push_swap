NAME = push_swap
BONUS_NAME = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
MAIN = push_swap.c
BONUS = checker.c
SRC = libft/*.c ft_printf/*.c Operations/*.c Utils/*.c
OBJ = obj/*.o
BONUS_SRC = libft/*.c ft_printf/*.c Operations/*.c Utils/*.c Bonus/*.c
BONUS_OBJ = obj_bonus/*.o

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(OBJ): $(MAIN) $(SRC)
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $(SRC) $(MAIN)
	@mv *.o obj/

$(BONUS_OBJ): $(BONUS) $(BONUS_SRC)
	@mkdir -p obj_bonus
	@$(CC) $(FLAGS) -c $(BONUS_SRC) $(BONUS)
	@mv *.o obj_bonus/

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ) obj obj_bonus

fclean:
	@$(RM) $(OBJ) $(BONUS_OBJ) $(NAME) $(BONUS_NAME) obj obj_bonus

re: fclean all

bonus_re: fclean bonus