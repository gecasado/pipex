NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRC = pipex.c ft_otherstr.c ft_other2.c ft_split.c ft_strtrim.c put.c
OBJ = $(SRC:.c=.o)
RM = rm -f

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
