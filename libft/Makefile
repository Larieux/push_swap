# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 18:29:02 by mlarieux          #+#    #+#              #
#    Updated: 2025/03/11 18:29:52 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c  ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_str_is_mult.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_strjoin.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdel.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c \

OBJ_PATH = obj/

OBJS = ${addprefix ${OBJ_PATH}, ${SRCS:.c=.o}}

OBJSB = ${addprefix ${OBJ_PATH}, ${SRCSB:.c=.o}}

CFLAGS = -Wall -Werror -Wextra -g

NAME = libft.a

all : ${OBJ_PATH} $(NAME)

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

$(NAME) : $(OBJS) $(OBJSB)
	ar rcs $(NAME) $^

${OBJ_PATH}%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

bonus : all

clean :
	rm -f $(OBJS) $(OBJSB)
	rm -rf $(OBJ_PATH)

fclean : clean
	 rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
