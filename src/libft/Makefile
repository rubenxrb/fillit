LIB = libft.a

CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Werror -Wextra
INC = -Iinc

ODIR = ./obj/
SDIR = ./src/

ADD = get_next_line
ADDIR = $(addprefix $(SDIR),$(ADD))
ADDS = $(wildcard $(ADDIR)/*.c)
ADDO = $(subst $(SDIR),$(ODIR),$(ADDS:.c=.o))
SRCN = 	memptrs.c memptrs2.c memptrs3.c		\
		convert.c convert2.c				\
		identifiers.c identifiers2.c		\
		strings.c strings2.c strings3.c		\
		strings4.c strings5.c strings6.c	\
		prints.c prints2.c prints3.c		\
		linkdlst.c linkdlst2.c				\
		btree.c	nbtree.c misc.c				\
		stack.c

OBJN =	$(SRCN:.c=.o)
SRC =	$(addprefix $(SDIR),$(SRCN))
OBJ =	$(addprefix $(ODIR),$(OBJN))

all: $(LIB)

$(LIB): src adds
	@ar rc $(LIB) $(ADDO)

src: mkobj $(OBJ) comp
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkobj:
	@mkdir -p $(ODIR)

comp:
	@ar rc $(LIB) $(OBJ)

adds: mkadds $(ADDO)
$(ADDO):$(ADDS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkadds: mkobj
	@mkdir -p $(addprefix $(ODIR),$(ADD))

clean:
	@$(RM) -rf $(ODIR)

fclean: clean
	@$(RM) -rf $(LIB)

re: fclean all
.PHONY: all clean fclean re
