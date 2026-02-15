NAME = rush-02
SRCS := $(wildcard *.c)

BASE = $(basename $(SRCS))
OBJS = $(addsuffix .o,$(BASE))

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.c header.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

all: $(NAME)