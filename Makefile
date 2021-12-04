NAME = main

$(NAME) : main.c
	clang -O3 -lmlx -L. -framework Metal -framework Metalkit -o $@ $<

test : $(NAME)

.PHONY : test