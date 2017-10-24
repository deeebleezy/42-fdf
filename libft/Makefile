# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/08 14:13:32 by dtuiasos          #+#    #+#              #
#    Updated: 2017/10/04 21:45:26 by dtuiasos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS += -Wall -Wextra -Werror
SRCS = ft_atoi.c \
	 		ft_bzero.c \
			ft_itoa.c \
			ft_mem{alloc,cpy,chr,cmp,ccpy,del,move,set}.c \
			ft_put{char,char_fd,endl,endl_fd,nbr,nbr_fd,str,str_fd}.c \
			ft_get_next_line.c \
			ft_valid_hex.c \
			ft_error.c \
			ft_arrsize.c \
			ft_atoi_strict.c \
			ft_atoi_base.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_str{iter,iteri}.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_str{map,mapi}.c \
			ft_strn{cat,cmp,cpy,equ,str}.c \
			ft_strrchr.c \
			ft_strnew.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_countwords.c \
			ft_strcoll.c \
			ft_to{lower,upper}.c \
			ft_lst{add,del,delone,iter,map,new}.c \
			ft_is{alnum,alpha,ascii,blank,digit,space,print,xdigit}.c \

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		@gcc $(CFLAGS) -c $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "You have been chosen to be taken on this journey..."

clean:
		@rm -rf $(OBJS)
		@echo "Hello, Neo... This is Morpheus"

fclean: clean
		@rm -rf $(NAME)

re: fclean all
