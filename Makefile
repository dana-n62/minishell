CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = minishell
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a
INCLD = -I$(LIBDIR) -I./includes
SRCDIR = ./srcs/
SRCS = $(SRCDIR)main.c $(SRCDIR)builtins/builtins.c $(SRCDIR)executor/executor.c \
	$(SRCDIR)lexer/lexer.c $(SRCDIR)lexer/lexer_utils.c $(SRCDIR)parser/parser.c \
	$(SRCDIR)signals/signals.c $(SRCDIR)env/env.c
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft -lreadline -o $(NAME)

%.o:%.c ./includes/minishell.h
	$(CC) $(CFLAGS) $(INCLD) -o $@ -c $<
$(LIBFT):
	$(MAKE) -C $(LIBDIR)
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBDIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean
re: fclean all
.PHONY: all clean fclean re
