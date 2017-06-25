# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 16:16:10 by sescolas          #+#    #+#              #
#    Updated: 2017/06/23 10:11:52 by sescolas         ###   ########.fr        #
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
OBJS = $(notdir $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) .objs/*.o $(LINK) -o $@

$(OBJS) : $(SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -Iincludes -c $(shell find . -name $(notdir $(@:.o=.c))) -o .objs/$@

$(LIBFT) : $(LIB_DEPS)
	make -C libft

.PHONY : clean fclean re print

print :
	@echo $(OBJS)

clean :
	rm -f libft/*\.o$
	rm -f .objs/*\.o$

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
