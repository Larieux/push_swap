# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 18:29:43 by mlarieux          #+#    #+#              #
#    Updated: 2025/03/11 18:29:44 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = p_s_utilities.c p_s_lst_utilities.c p_s_swap_and_push.c p_s_rotate.c \
	p_s_errors_init.c p_s_sort_two_or_three.c p_s_low_high_first.c \
	p_s_costs.c p_s_sort.c p_s_low_high_last.c p_s_last.c p_s_algorithm.c \
	push_swap.c \

OBJ_PATH = obj/

OBJS = ${addprefix ${OBJ_PATH}, ${SRCS:.c=.o}}

CFLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

NAME = push_swap

all : ${OBJ_PATH} $(LIB) $(NAME)

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

${OBJ_PATH}%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB) :
	$(MAKE) -C libft bonus

clean :
	$(MAKE) -C libft clean
	$(RM) $(OBJS)
	rm -rf $(OBJ_PATH)

fclean : clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all $(LIB)
