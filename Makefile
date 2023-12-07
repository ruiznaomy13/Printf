# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 19:16:59 by ncastell          #+#    #+#              #
#    Updated: 2023/12/07 16:53:29 by ncastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER 	= inc/ft_printf.h
MKFL	= Makefile
NAME 	= libftprintf.a

OBJ_DIR	= obj/
LIB_DIR = lib/Libft/
LIB		= $(LIB_DIR)libft.a

SRC 	= src/ft_printf.c src/ft_format.c

RM 		= rm -rf
MP		= mkdir -p

CFLAGS 	= -Werror -Wall -Wextra -W -O3 -Ofast 

LIBC 	= ar -rcs

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP	= $(addsuffix .d, $(basename $(OBJ)))

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} ${CFLAGS} -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) -C $(LIB_DIR) 
	@$(MAKE) $(NAME)

-include ${DEP}
$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ) $(LIB)

testmain:
	gcc main.c libftprintf.a

clean:
	$(RM) $(OBJ) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIB_DIR)

fclean:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:
	@$(MAKE) re -C $(LIB_DIR)
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
