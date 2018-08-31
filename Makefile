# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 09:57:35 by cbester           #+#    #+#              #
#    Updated: 2018/07/20 06:36:12 by cbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./cbester.filler
MAP = resources/maps/map01
FILLER = ./resources/filler_vm
VML = https://projects.intra.42.fr/uploads/document/document/321/resources.zip
VM = ./resources

LIBRARY_NAME = libft.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))

FLAGS = -Wall -Wextra -Werror

FILES_DIR = ./includes/
FUNCTIONS = check_score.c nojunk.c strategy.c data_reader.c free_data.c\
			newtrim.c place.c place_alt.c player_data.c main.c
FILES = $(addprefix $(FILES_DIR), $(FUNCTIONS))

OBJECTS = $(FILES:.c=.o)

all: $(NAME) vm

$(NAME): $(LIBRARY_NAME) $(OBJECTS)
	@gcc $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBRARY)
	@echo "\033[37mPlayer Created!\033[0m"

$(LIBRARY_NAME):
	@make -C ./libft/

%.o: %.c
	@echo "\033[36mCreating Objects $@\033[0m"
	@gcc $(FLAGS) -c $< -o $@

vm:
	@if test ! -d $(VM); then \
		echo "\033[37mDowloading Filler VM resources...\033[0m"; \
		curl -O $(VML); \
		echo "\033[37mUnzipping resources.zip...\033[0m"; \
		unzip resources.zip; \
		cp extra_maps/map* resources/maps/; \
		echo "\033[37mAdding extra maps...\033[0m"; \
		echo "\033[37mRemoving resources.zip...\033[0m"; \
		echo "\033[37mVM Download Complete!\033[0m"; \
		rm resources.zip; \
	fi; \

.PHONY: clean fclean uclean re vm solo

solo:
	$(FILLER) -p1 $(NAME) -v -f $(MAP)

clean:
	@echo "\033[33mRemoving filler object files...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[33mRemoving filler.h..gch file\033[0m"
	@/bin/rm -f ./header/filler.h.gch
	@echo "\033[33mRemoving filler.trace\033[0m"
	@/bin/rm -f ./filler.trace
	@make clean -C ./libft/
	@echo "\033[37mAI clean completed!\033[0m"

fclean:
	@echo "\033[33mRemoving filler object files...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[33mRemoving filler.h.gch file\033[0m"
	@/bin/rm -f ./header/filler.h.gch
	@echo "\033[33mRemoving filler.trace\033[0m"
	@/bin/rm -f ./filler.trace
	@echo "\033[33mRemoving player AI\033[0m"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft/
	@echo "\033[37mAI fclean completed!\033[0m"

uclean:
	@echo "\033[33mRemoving filler object files...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[33mRemoving filler.h.gch file\033[0m"
	@/bin/rm -f ./header/filler.h.gch
	@echo "\033[33mRemoving filler.trace\033[0m"
	@/bin/rm -f ./filler.trace
	@echo "\033[33mRemoving player AI\033[0m"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft/
	@/bin/rm -rf ./resources/
	@echo "\033[37mResources Removed!\033[0m"
	@echo "\033[37mAI uclean completed!\033[0m"

re: fclean all

reu: uclean all
