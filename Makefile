# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 16:16:10 by sescolas          #+#    #+#              #
#    Updated: 2017/09/01 17:25:57 by sescolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
LIB_DEPS = $(shell ls  libft/*.c)

TO_LINK = ft termcap
LINK = -L libft $(foreach LIB,$(TO_LINK), -l$(LIB))

HEADERS = $(wildcard includes/*.h$)
SRC_DIRS = build builtins input lexer types utils
SRCS = $(foreach DIR,$(SRC_DIRS), $(addprefix ,$(wildcard srcs/$(DIR)/*.c$)))
OBJS = $(foreach OBJ,$(notdir $(SRCS:.c=.o)),.objs/$(OBJ))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) .objs/*.o $(LINK) -o $@

$(OBJS) : $(SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -Iincludes -c $(shell find . -name $(notdir $(@:.o=.c))) -o $@

$(LIBFT) : $(LIB_DEPS)
	make -C libft

.PHONY : clean fclean re print

print :
	@echo $(OBJDEPS)

clean :
	rm -f libft/*\.o$
	rm -f .objs/*\.o$

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
