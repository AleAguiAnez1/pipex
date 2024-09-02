# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaguirr <alaguirr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 11:09:28 by alaguirr          #+#    #+#              #
#    Updated: 2024/09/02 12:49:30 by alaguirr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g
SRCS = pipex.c path.c error.c make.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	@if [ ! -f $(LIBFT) ]; then \
		echo "Error: libft.a not found in $(LIBFT_DIR)"; \
		exit 1; \
	fi

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	chmod +x $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	chmod +x $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
