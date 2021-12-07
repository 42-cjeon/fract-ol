CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_ROOT)
RM = rm -f
NAME = fractal

SRCS_ROOT = srcs
INCLUDES_ROOT = includes
OBJS_ROOT = objs
MLX_ROOT = $(SRCS_ROOT)/minilibx

SRCS = calc_escape_time.c fract_ol.c ft_complex.c init_complex.c paint_fractal.c \
		coloring.c keyboard_handler.c display_fractal.c utils.c mouse_handler.c
OBJS = $(addprefix $(OBJS_ROOT)/, $(SRCS:.c=.o))
MLX = $(MLX_ROOT)/libmlx.a

vpath %.c $(SRCS_ROOT)
vpath %.h $(INCLUDES_ROOT)

$(NAME) : $(OBJS) $(MLX) 
	$(CC) -O3 -lmlx -L$(MLX_ROOT) -framework OpenGL -framework AppKit -o $@ $^

$(OBJS_ROOT)/%.o : $(SRCS_ROOT)/%.c $(INCLUDES_ROOT)/%.h $(INCLUDES_ROOT)/constants.h
	$(CC) -O3 -c $(CFLAGS) -o $@ $<

$(MLX) :
	$(MAKE) -C $(MLX_ROOT) all

all : $(NAME)

bonus : all

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_ROOT) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re