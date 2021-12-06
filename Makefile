CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_ROOT)
RM = rm -f
NAME = fractal

SRCS_ROOT = srcs
INCLUDES_ROOT = includes
OBJS_ROOT = objs
MLX_ROOT = $(SRCS_ROOT)/minilibx

SRCS = calc_escape_time.c fract_ol.c ft_complex.c init_complex.c paint_fractal.c
OBJS = $(addprefix $(OBJS_ROOT)/, $(SRCS:.c=.o))
#MLX = $(MLX_ROOT)/libmlx.dylib

MLX = libmlx.a

vpath %.c $(SRCS_ROOT)
vpath %.h $(INCLUDES_ROOT)

$(NAME) : $(OBJS) $(MLX) 
	clang -O3 -lmlx -L$(MLX_ROOT) -framework OpenGL -framework AppKit -o $@ $^

$(OBJS_ROOT)/%.o : $(SRCS_ROOT)/%.c $(INCLUDES_ROOT)/%.h $(INCLUDES_ROOT)/constants.h
	$(CC) -O3 -c $(CFLAGS) -o $@ $<

$(MLX) :
	$(MAKE) -C $(MLX_ROOT) all

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_ROOT) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re