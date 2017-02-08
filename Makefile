NAME 	=fillit

SRC 	=	main.c \
		ft_fillit.c \
		ft_pieces.c \
		ft_validation.c \
		ft_board.c \
		ft_getboard.c

OD 		= objs
ODIR	= ./$(OD)/
SDIR	= ./srcs/
FSDIR	= $(SDIR)fillit-source/
OBJ		= $(addprefix $(ODIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LDIR	= $(SDIR)libft/
LIB		= $(LDIR)libft.a

LIBINC	= -I$(LDIR)
LIBLINK	= -L $(LDIR) -lft

all: $(NAME)

$(NAME): $(OD) $(LIB) $(OBJ)
	$(CC) $(LIBLINK) $(OBJ) -o $(NAME)

$(OD):
	mkdir -p $(ODIR)

$(LIB):
	make -C $(LDIR)

obj:
	mkdir -p $(ODIR)

$(ODIR)%.o:$(FSDIR)%.c
	$(CC) $(FLAGS) $(LIBINC) -c -o $@ $^

clean:
	rm -rf $(ODIR)
	make -C $(LDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: clean all re fclean
