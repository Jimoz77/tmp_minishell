# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 14:00:24 by lsadikaj          #+#    #+#              #
#    Updated: 2025/04/17 16:24:34 by jimpa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = minishell

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

# Dossiers
SRC_DIR = source
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers source
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/ft_getcwd.c \
	$(SRC_DIR)/ft_read_line.c \
	$(SRC_DIR)/built-in/ft_cd.c \
	$(SRC_DIR)/built-in/ft_echo.c \
	$(SRC_DIR)/built-in/ft_env.c \
	$(SRC_DIR)/built-in/ft_export.c \
	$(SRC_DIR)/built-in/ft_is_builtin.c \
	$(SRC_DIR)/built-in/ft_pwd.c \
	$(SRC_DIR)/built-in/ft_unset.c \
	$(SRC_DIR)/tokenizer/tokenizer.c \
	$(SRC_DIR)/tokenizer/tokenizer_utils.c \
	$(SRC_DIR)/tokenizer/tokenizer_handle.c \
	$(SRC_DIR)/tokenizer/envar_to_value.c \
	$(SRC_DIR)/parser/parser.c \
	$(SRC_DIR)/parser/parser_utils.c \
	$(SRC_DIR)/parser/parser_ops.c \
	$(SRC_DIR)/parser/parser_parentheses.c \
	$(SRC_DIR)/parser/parser_syntax.c \
	$(SRC_DIR)/parser/parser_syntax2.c \
	$(SRC_DIR)/utils/memory_utils.c \
	$(SRC_DIR)/utils/ft_array_dup.c \
	$(SRC_DIR)/utils/ft_path_finder.c \

# Fichiers objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation des fichiers objets dans les sous-dossiers
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compilation de l'exécutable
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Règle principale
all: $(NAME)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
