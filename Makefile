##
## Makefile for my_ftl in /home/meurin/Desktop/FTL/meurin_r
## 
## Made by MEURIN Remy
## Login   <meurin_r@etna-alternance.net>
## 
## Started on  Fri Nov 10 13:49:40 2017 MEURIN Remy
## Last update Fri Nov 10 13:49:42 2017 MEURIN Remy
##
CC = gcc # C compiler
CFLAGS = -fPIC -g -W -Werror -Wall# C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
NAME = libmy_malloc_$(shell uname).so # target lib

SRCS = malloc.c # source files
OBJS = $(SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
	ln -s $(NAME) libmy_malloc.so

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

clean: 
	-${RM} ${OBJS} $(SRCS:.c=.d)
	unlink libmy_malloc.so

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re