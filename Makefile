##
## Makefile for Makefile in /home/henry_g/rendu
## 
## Made by Clément Henry
## Login   <henry_g@epitech.net>
## 
## Started on  Fri Dec  5 22:21:16 2014 Clément Henry
## Last update Fri Mar 25 17:19:02 2016 Clément
##

SRC=	main.c \
	get_env.c \
	do_it.c \
	copy_env.c \
	minishell.c \
	open.c \
	epur_str.c \
	get_next_line.c \
	str_to_wordtab.c \
	my_exec.c \
	builtin.c \
	builtin_2.c \
	exit.c \
	set_env.c \
	split_array.c \
	my_strcat.c \
	unset.c \
	str_dup.c \
	needs.c

NAME=	mysh

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -lncurses  -o $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
