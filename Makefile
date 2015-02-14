##
## Makefile for makefile in /home/danilo_d/rendu/MUL_2014_fdf
## 
## Made by Dimitri Danilov
## Login   <danilo_d@epitech.net>
## 
## Started on  Sun Nov 16 14:20:35 2014 Dimitri Danilov
## Last update Sun Dec  7 21:15:25 2014 Dimitri Danilov
##

NAME	= fdf

LIBNAME	= libmy

LIBFO	= lib/my/

SRCSFO	= srcs/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)draw.c \
	  $(SRCSFO)fdf.c \
	  $(SRCSFO)str_to_tab.c \
	  $(SRCSFO)gere_even.c

LIBSRCS	= $(LIBFO)my_get_nbr.c \
	  $(LIBFO)get_next_line.c \
	  $(LIBFO)xmalloc.c \
	  $(LIBFO)my_display.c

OBJS	= $(SRCS:.c=.o)

LIBOBJS	= $(LIBSRCS:.c=.o)

CFLAGS	+= -I./include/ -Wall -pedantic -Werror -g

COMPIL  = -lmlx -L/usr/lib64 -lmy -Llib -L/usr/lib64/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(LIBNAME).a $(LIBOBJS)
	ranlib $(LIBNAME).a
	mv $(LIBNAME).a lib
	cc -o $(NAME) $(OBJS) $(CFLAGS) $(COMPIL)

clean:
	rm -f $(OBJS)
	rm -f $(LIBOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f lib/my/$(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
