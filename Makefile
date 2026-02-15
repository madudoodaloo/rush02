NAME = rush-02
SRCS = $(*.c)

BASE = $(basename $(SRCS))
OBJS = $(addsuffix .o,$(BASE))

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -c $< -o $@ -I header.h

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

all: $(NAME)