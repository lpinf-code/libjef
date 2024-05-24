##
## EPITECH PROJECT, 2023
## libjef
## File description:
## JSON Extraction Framework
##

NAME = libjef.a

SRC = $(shell find src -name '*.c')

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Iinclude

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ);

all:  $(NAME)
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

main_test: CFLAGS += -g3
main_test: $(NAME)
	gcc -o tests/module_tests debug/*.c -Iinclude -L. -ljef -g3
	chmod a+x tests/module_tests

re: fclean all

tests_clean:
	(cd tests/; rm -f *.gc* *.o)
	find -name "vgcore.*" -delete;

tests_fclean: tests_clean
	rm -f tests/module_tests


unit_tests: tests_fclean $(NAME)
	gcc -o tests/module_tests tests/*.c -Iinclude \
		-lcriterion -L. -ljef --coverage
	chmod a+x tests/module_tests

tests_run: unit_tests
	(cd tests/; ./module_tests)

.PHONY: all tests_clean tests_fclean unit_tests tests_run clean fclean re
