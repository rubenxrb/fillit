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
INC = $(LIBINC) -I$(IDIR)

all: $(MAIN)

$(MAIN): lib mkobj $(OBJ)
	$(CC) $(LDIR)libft.a $(OBJ) -o $(MAIN)

lib:
	make -C $(LDIR)

mkobj:
	mkdir -p $(ODIR)

$(ODIR)%.o:$(SDIR)%.c
	$(CC) $(INC) -c -o $@ $^

clean:
	rm -rf $(ODIR)
	make -C $(LDIR) clean

fclean: clean
	rm -rf $(MAIN)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: clean all re fclean
