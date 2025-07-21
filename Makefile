### ARGUMENTS ###
NAME = pipex
CFLAGS = -Wall -Werror -Wextra
CC = cc
INCLUDES = -Iinc

### SOURCES ###
SRCS = src/pipex.c \
src/get_path_and_cmd_args.c \
src/get_cmd_args_utils.c \
src/handle_errors_and_frees.c \
src/pipex_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

### RULES ###
all : $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re