SRCS			= main.c all_checks1.c  all_checks2.c get_next_line.c get_next_line_utils.c so_long_utils.c moves.c mlx.c so_long_utils2.c

SRCS_B			= all_checks2_bonus.c get_next_line_bonus.c main_bonus.c moves_bonus.c so_long_utils_bonus.c all_checks1_bonus.c ft_itoa_bonus.c get_next_line_utils_bonus.c mlx_bonus.c generate_coins_bonus.c enemy_move_bonus.c enemy_loop_bonus.c so_long_utils2_bonus.c

NAME			= so_long

NAME_B			= so_long_bonus

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

AR				= ar rc 

OBJS			= $(SRCS:.c=.o)

OBJS_B			= $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cc ${CFLAGS} ${OBJS}  -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B)
	cc ${CFLAGS} ${OBJS_B}  -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all
