ifeq ($(shell uname -s), Darwin)
CC = /opt/homebrew/Cellar/llvm/13.0.0_2/bin/clang
else
CC = gcc
endif

all :
	$(CC) -Wall -Wextra -Werror -fsanitize=address -g3 main.c execute.c libft.a -o micro_ast

valgrind :
	 $(CC) -Wall -Wextra -Werror -g3 main.c execute.c libft.a -o micro_ast

clean :
	rm -f micro_ast
	rm -rf micro_ast.dSYM
