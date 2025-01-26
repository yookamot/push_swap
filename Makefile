# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 20:35:23 by yookamot          #+#    #+#              #
#    Updated: 2025/01/11 21:24:50 by yookamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = calculate_best_move.c \
		check_arg.c \
		copy_argv.c \
		create_stack.c \
		format_arguments.c \
		free_array.c \
		free_stack.c \
		get_position.c \
		main.c \
		map_to_rank.c \
		push_reference.c \
		push.c \
		return_arraysize.c \
		reverse_rotate.c \
		rotate_system.c \
		rotate.c \
		sort_large_tark.c \
		sort_small.c \
		sort_three.c \
		sort.c \
		swap.c \
		

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
