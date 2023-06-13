# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:09:46 by twang             #+#    #+#              #
#    Updated: 2023/06/13 14:59:46 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/print.mk
include config/sources.mk
include config/headers.mk

.SILENT:

#--variables-------------------------------------------------------------------#

NAME		=	philo
DEBUG		=	no
VALGRIND	=	no
TWANG		=	\e]8;;https://profile.intra.42.fr/users/twang\a\e[34mtwang\e[34m\e]8;;\a

#--includes--------------------------------------------------------------------#

INC_DIR		=	incs

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	sources
OBJ_DIR		=	.objs

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -I $(INC_DIR) #-Werror

#--debug flags-----------------------------------------------------------------#

DFLAGS		=	-g3 -fsanitize=address #-fsanitize=thread -g
ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

LEAKS		= valgrind --tool=helgrind

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) header
	$(MAKE) $(NAME) -j

$(NAME): $(OBJECTS)
	$(CC) $^ $(CFLAGS) -o $@ -pthread
	$(PRINT_CREATING)

$(OBJ_DIR)/%.o: %.c $(HEADERS) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(PRINT_COMPILING)

#--debugs & errors detector----------------------------------------------------#

debug:
	$(MAKE) re -j DEBUG=yes

leaks:
	clear
	$(MAKE) re -j VALGRIND=yes
	$(LEAKS) ./philo 5 200 200 200 200

#--print header----------------------------------------------------------------#

header:
	printf "\n${PURPLE}project:\t${END}${BLUE}philosophers${END}\n"
	printf "${PURPLE}author:\t\t${END}${BLUE}${TWANG}${END}\n"
	printf "${PURPLE}debug mode:\t${END}${BLUE}${DEBUG}${END}\n"
	printf "${PURPLE}compiler:\t${END}${BLUE}${CC}${END}\n"
	printf "${PURPLE}flags:\t\t${END}${BLUE}${CFLAGS}${END}\n"
	printf "${PURPLE}date:\t\t${END}${BLUE}2023/06/05${END}\n"
	printf "              ____________________________\n\n"

#--re, clean & fclean----------------------------------------------------------#

re:
	clear
	$(MAKE) fclean
	$(MAKE) -j all

clean:
	$(RM) -rf $(OBJECTS)
	$(PRINT_CLEAN)

fclean:
	clear
	$(MAKE) clean
	$(RM) $(NAME)
	$(PRINT_FCLEAN)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all debug header re clean fclean
