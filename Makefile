NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= ft_printf.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_hex.c \
			  ft_print_ptr.c

OBJS		= $(SRCS:.c=.o)

CYAN		= \033[1;36m
GREEN		= \033[1;32m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) --no-print-directory banner

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

banner:
	@printf "$(CYAN)\n"
	@printf '%s\n' \
	'    ______                   _       __  ____' \
	'   / __/ /_      ____  _____(_)___  / /_/ __/' \
	'  / /_/ __/     / __ \/ ___/ / __ \/ __/ /_  ' \
	' / __/ /_      / /_/ / /  / / / / / /_/ __/  ' \
	'/_/  \__/_____/ .___/_/  /_/_/ /_/\__/_/     ' \
	'       /_____/_/                             '
	@printf "\n$(RESET)$(GREEN)libftprintf.a compiled successfully$(RESET)\n"

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all banner clean fclean re