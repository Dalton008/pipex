NAME = pipex

HEADER = includes/pipex.h

LIST = ft_split.c utils.c pipex.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(LIST:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

${NAME} : $(OBJ) $(HEADER)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all