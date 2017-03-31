MAIN = fillit

SRC = main.c fillit.c pieces.c	\
      validation.c board.c	\
      getboard.c

ODIR = ./obj/
SDIR = ./src/
IDIR = ./inc/
OBJ = $(addprefix $(ODIR),$(SRC:.c=.o))
CC = gcc -Wall -Wextra -Werror

LDIR = $(SDIR)libft/
LIBINC	= -I$(LDIR)inc/
INC = -I$(IDIR)

all: $(MAIN)

$(MAIN): src
	@$(CC) -o $(MAIN) $(OBJ) $(INC) $(LDIR)libft.a
	@echo "[./fillit] <compiled>"

src: lib mkobj $(OBJ)
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(LIBINC) $(INC) -o $@ -c $<

lib:
	@make -s -C $(LDIR)

mkobj:
	@mkdir -p $(ODIR)

clean:
	@rm -rf $(ODIR)
	@make -s -C $(LDIR) clean
	@echo "[./obj/] <deleted>"

fclean: clean
	@rm -rf $(MAIN)
	@make -s -C $(LDIR) fclean
	@echo "[./fillit] <deleted>"

re: fclean all

.PHONY: clean all re fclean
