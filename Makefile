# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 09:28:51 by hefurrer          #+#    #+#              #
#    Updated: 2023/01/09 09:28:54 by hefurrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CLIENT	:=	client
SERVER	:=	server

SRCS	:=	server.c
OBJS	:=	$(SRCS:.c=.o)

SRCC	:=	client.c
OBJC	:=	$(SRCC:.c=.o)

LIBS	:=	ft
LIBS_TARGET	:=	libft/libft.a

INCS	:=	libft

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(SERVER) -fsanitize=address

$(CLIENT): $(OBJC) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJC) $(LDLIBS) -o $(CLIENT) -fsanitize=address

$(LIBS_TARGET):
	make -C $(@D)

clean:
	make -C ./libft clean
	$(RM) $(OBJS) $(OBJC)

fclean: clean
	make -C ./libft fclean
	$(RM) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY: all bonus clean fclean re
