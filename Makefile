# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilips <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 16:06:34 by gphilips          #+#    #+#              #
#    Updated: 2017/02/07 15:59:11 by gphilips         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c init.c create_win.c read_file.c map.c draw.c event.c
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
LIBDIR = libft/
LIB = libft.a
LIBPATH = $(addprefix $(LIBDIR), $(LIB))
OBJ = $(SRC:.c=.o)

all: $(NAME)

.PHONY: all clean fclean re

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $@ $(OBJ) $(LIBPATH) $(MLX)
	@echo "$@ created"

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
