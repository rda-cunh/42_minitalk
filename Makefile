# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:06:59 by rda-cunh          #+#    #+#              #
#    Updated: 2024/05/25 23:50:16 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
# NAME_CBONUS = client_bonus
# NAME_SBONUS = server_bonus

SRC_S = server.c
SRC_C = client.c
# SRC_CBONUS = client_bonus.c
# SRC_SBONUS = server_bonus.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
# OBJ_SBONUS = $(SRC_SBONUS:.c=.o)
# OBJ_CBONUS = $(SRC_CBONUS:.c=.o)

LIBFT       = ./libft/libft.a
LIBFTDIR    = ./libft

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)

$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C ${LIBFTDIR}

# bonus: $(OBJ_SBONUS) $(OBJ_CBONUS) $(LIBFT)
#       $(FLAGS) $(OBJ_SBONUS) $(LIBFT) -o $(NAME_S)
#       $(FLAGS) $(OBJ_CBONUS) $(LIBFT) -o $(NAME_C)

clean:  
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJ_S) $(OBJ_C) 
#       $(RM) $(OBJ_SBONUS) $(OBJ_CBONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME_S) $(NAME_S)
#       $(RM) $(NAME_SBONUS) $(NAME_CBONUS)

re: fclean all

.PHONY: all bonus clean fclean re