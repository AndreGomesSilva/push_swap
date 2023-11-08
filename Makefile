# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 20:33:19 by angomes-          #+#    #+#              #
#    Updated: 2023/11/01 16:29:07 by angomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS = -I ./inc
CFLAGS = -Wall -Wextra -Werror
LEAKS = valgrind --leak-check=full --show-leak-kinds=all
RM = rm -f
CC = cc -g
SRCS_DIR = src
OBJS_DIR = obj
BIN = push_swap
NAME = $(BIN)
LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
ARGS = 12 32

FILES =\
	push_swap \
	handle_nodes \
	check_args \
	handle_free \
	swap \
	rotate \
	push \

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft $(HEADERS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

$(LIBFT):
	$(MAKE)	-C $(LIBFT_PATH)

play: all
	./$(BIN) $(ARGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(BIN)

re: fclean all

.PHONY: all clean fclean re
