# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 15:13:26 by bbeldame          #+#    #+#              #
#    Updated: 2017/08/27 16:11:05 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra #-Werror
	
LIBFTA = libft.a

LIBFTDIR = ./libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/

SRCS_NAME = lem_in.c parse_utils.c

OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(LIBFT):
		@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) obj $(OBJS)
		@gcc $(OBJS) $(LIBFT) -lm -o $(NAME)
			@echo "$(GREEN)---------lem-in compiled----------$(NC)"

norme:
		@norminette includes srcs

clean:
		@rm -rf $(OBJDIR)
		@make clean -C $(LIBFTDIR)

fclean:	clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFTDIR)
		@echo "$(GREEN)----lem-in removed completely-----$(NC)"

re: fclean all
