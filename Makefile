# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseinic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 16:27:43 by mseinic           #+#    #+#              #
#    Updated: 2016/08/19 15:55:10 by mseinic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project

WAVE_PATH:=wave/
WAVE_FILES:=wave_info wave_reverse wave_delete wave_load \
	wave_save wave_get wave_new wave_set wave_scale wave_canal wave_crop wave_add_signal

MENU_PATH:=menu/
MENU_FILES:=menu

ARGS_PATH:=args/
ARGS_FILES:=args process_args

OTHER_PATH:=other/
OTHER_FILES:=endians ft_memdel

MAIN_PATH:=main/
MAIN_FILES:=main opt_functions menu_functions crop_aux

FILES:=

SRC_PATH:=src/

HEADERS_PATH:=includes/

CACHE_PATH:=cache/

COMPILER:=gcc 

CFLAGS:= -g3 -Wall -Wextra #-Werror

INCF:= -I $(HEADERS_PATH) -lm #-lncurses

#ALL_FLAGS:=$(CFLAGS) -I $(HEADERS_PATH) -lm -lncurses

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
FILES+=$(addprefix $(WAVE_PATH),$(WAVE_FILES))
FILES+=$(addprefix $(ARGS_PATH),$(ARGS_FILES))
FILES+=$(addprefix $(MENU_PATH),$(MENU_FILES))
FILES+=$(addprefix $(OTHER_PATH),$(OTHER_FILES))
FILES+=$(addprefix $(MAIN_PATH),$(MAIN_FILES))

SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(CACHE_PATH),$(addsuffix .o,$(FILES)))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bolt---------#
#-------I = Intense------#
#-------U = Underline----#
Green = "\033[0;32m"
B_I_Red = "\033[1;91m"
Yellow  = "\033[0;33m"
END     = "\033[0m"
#-----------------COLORS------------------#

all: $(NAME)

#======= compiling NAME file =======
$(NAME): $(OBJ)
	@echo $(Yellow) " Compiling ---> $@ <---" $(END)
	@$(COMPILER) $(OBJ) -o $@ $(INCF) 
	@echo $(Green) " !!! Ready !!!" $(END)

#======= compiling *.c in *.o ======
$(CACHE_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(CACHE_PATH)
	@mkdir -p $(CACHE_PATH)$(WAVE_PATH)
	@mkdir -p $(CACHE_PATH)$(ARGS_PATH)
	@mkdir -p $(CACHE_PATH)$(MENU_PATH)
	@mkdir -p $(CACHE_PATH)$(OTHER_PATH)
	@mkdir -p $(CACHE_PATH)$(MAIN_PATH)
	@echo $(Green)" Creating $(NAME) :  $@ with $< " $(END)
	@$(COMPILER) $(CFLAGS) -o $@ -c $< $(INCF)
%.c:
	@echo $(B_I_Red) "Missing file : $@" $(END)


clean:
	@echo $(B_I_Red) "Deleting $(CACHE_PATH)" $(END)
	@/bin/rm -rf $(CACHE_PATH)
	@/bin/rm -rf $(CACHE)
fclean: clean
	@echo $(B_I_Red) "Deleting $(NAME)" $(END)
	@/bin/rm -rf $(NAME)
re: fclean all

test:
	@echo "obj :" $(OBJ)
	@echo "files :" $(SRC)
	@echo "headers :" $(HEADERS_PATH)

.PHONY: all clean fclean re
