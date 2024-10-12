# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obahi <obahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 02:43:15 by obahi             #+#    #+#              #
#    Updated: 2023/12/12 02:43:18 by obahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = 	ft_atoi.c \
		ft_atoll.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_free.c \
		ft_free2.c \
		ft_isalnum.c  \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putstrstr_fd.c \
		ft_split.c \
		ft_str_join.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoin_.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strstrdup.c \
		ft_strstrlen.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_word_count.c \
		get_next_line.c \
		ft_strcmp.c 
BSRC = 	ft_lstadd_back.c \
		ft_lstadd_front.c  \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
HEADER = libft.h
RM = rm
AR = ar

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) cr $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(BOBJ)
	$(AR) cr $(NAME) $(BOBJ)

clean :
	$(RM) -f $(OBJ)  $(BOBJ)

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
