NAME = fdf
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft/
SRCDIR = srcs/
FILES = main.c create_win.c

SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) $(SRC) -L $(LIBDIR) $(MLX) -o $(NAME)
	@echo "$(NAME) created"


clean:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from fdf"

fclean:
	@make fclean -C $(LIBDIR)
	@rm -f $(OBJ)
	@echo "Erasing .o files from fdf"
	@rm -f $(NAME)
	@echo "Erasing $(NAME)"

re: fclean all
