#------ TARGET ------#
NAME		:= $(notdir $(CURDIR))
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 -Werror #-Wunused
INCLUDES	+= -I include/
#------ SRC FILES & DIRECTORIES ------#
SRC_DIR		:= src/
SRC			:=  $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')
PROJECT_ROOT:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../)
GIT_REPO	:=$(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
DIRS		:= $(abspath $(dir $(shell find $(PROJECT_ROOT) -name Makefile | sort)))
CURRENT		:= $(shell basename $$PWD)
DEBUG_FILES	:= debug
#------ DEBUG FLAG ------#
D			= 1
#------ Sanitizer Flag ------#
S			= 0
#------ DEBUG UTILS ------#
CC			:= c++
MAKEFLAGS	+= --no-print-directory
VALGRIND	:= valgrind -s --leak-check=yes --show-leak-kinds=all
HELGRIND	:= valgrind -s --tool=helgrind
MAC_LEAKS	:= leaks -atExit --
BUILD_DIR	:= .build/
DEBUG_DIR	:= $(NAME).dSYM

#------ ADDING DEBUG FLAGS ------#
ifneq ($(D), 0)
CC			= g++
SRC			+= $(shell find $(DEBUG_FILES) -name '*.cpp')
INCLUDES	+= -I $(DEBUG_FILES)/include
D_FLAGS		+= -DDEBUG=$(D)
else
SRC			+= $(SRC_DIR)main.cpp
endif
ifeq ($(S), 0)
#MAKEFLAGS	+= --debug
OBJS		:= $(SRC)
else
#------ CODE FOR OBJECT FILES ------#
OBJS := $(addprefix $(BUILD_DIR), $(notdir $(SRC:%.cpp=%.o)))
# The `vpath` directive in a Makefile is used to specify a list of directories
# that `make` should search when it's looking for prerequisites.
vpath %.cpp $(sort $(dir $(SRC)))
# OBJS := $(patsubst $(SRC_DIR)%.cpp,$(nodir ($(BUILD_DIR)%.o)),$(SRC))
DEPS		:= $(OBJS:.o=.d)
#------ INCLUDE SANATIZER FLAGS ------#
D_FLAGS		+= -O0 -g3
D_FLAGS		+= -fsanitize=address,undefined
endif
#-------------------- RULES ----------------------------#
all: $(NAME)

$(NAME): $(OBJS)
ifneq ($(S), 0)
	@printf "$(LF)\n🚀 $(P_BLUE)Successfully Created $(P_YELLOW)$(NAME)'s Object files 🚀$(FG_TEXT)\n"
endif
	@printf "\n"
	@printf "$(LF)📚 $(P_BLUE)Create $(P_GREEN)$@ 📚\n"
	@echo $(GREEN)
	@printf "$(CC) $(D_FLAGS) $(INCLUDES) $(P_YELLOW) $^ $(P_GREEN) -o $@ $(FG_TEXT) \n\n";
	@$(CC) $(D_FLAGS) $(INCLUDES) $^ -o $(NAME)
	@printf "\n$(LF)🎉 $(P_BLUE)Successfully Created $(P_GREEN)$@! 🎉\n$(P_NC)"
	@echo $(BANNER)

ifneq ($(S), 0)
$(OBJS): $(BUILD_DIR)%.o : %.cpp | $(BUILD_DIR)
	@$(CC) $(D_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "$(LF)🚧 $(P_BLUE)Creating $(P_YELLOW)$@ $(P_BLUE)from $(P_YELLOW) $< $(FG_TEXT)"

$(BUILD_DIR):
	@mkdir -p $@
endif

clean:
	@echo $(RED)
	@if [ -d "$(BUILD_DIR)" ]; then	\
		rm -rf $(BUILD_DIR); 		\
		printf "$(LF)🧹🗑️ $(P_RED) Clean $(P_YELLOW)$(NAME)'s Object files$(P_NC)\n"; \
	fi
	@if [ -d "$(DEBUG_DIR)" ]; then	\
		rm -rf $(DEBUG_DIR); 		\
	fi
	@printf  "\n$(P_NC)"

fclean: clean
	@if [ -f "$(NAME)" ]; then	\
		printf "$(LF)🧹🗑️ $(P_RED) Clean $(P_GREEN) $(CURRENT)/$(NAME)\n";	\
		rm -rf $(NAME);														\
		echo $(TRASH_BANNER);												\
	else																	\
		printf "$(LF)🧹🗑️ $(P_RED) Clean $(P_GREEN) $(CURRENT)\n";			\
	fi
	@printf "\n$(P_NC)"

re: fclean all

.PHONY: all clean fclean re
#------------- TEST UTILS -----------------------------------#
test:$(NAME)
	@echo $(BOLD) $(CYAN) ./$(NAME) $(E_NC) "\n"
	@./$(NAME) | cat
#	@echo "-----\n"
# ATTENTION !!!!!!!!!!!!!!  USE WITH S=0 !
leaks: $(NAME)
	@echo $(RED)$(MAC_LEAKS) ./$(NAME) $(E_NC)  "\n"
	@$(MAC_LEAKS) ./$(NAME)
	@echo "\n"

val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) $(E_NC) "\n"
	@$(VALGRIND) ./$(NAME)
	@echo "\n"

# #-------------------- GIT UTILS ----------------------------#
dirs:
	@echo GIT_REPO:  $(CYAN) $(GIT_REPO) $(E_NC)
	@echo PROJECT_ROOT: $(CYAN) $(PROJECT_ROOT) $(E_NC)
	@echo DIRS: $(BOLD) $(DIRS) "\n" $(E_NC)
	@echo CURRENT: $(GREEN) $(CURRENT) $(E_NC)
	@echo SRC: $(YELLOW) $(SRC) $(E_NC)
	@echo OBJS: $(GRAY) $(OBJS) $(E_NC)
testAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir D=$(D) test; \
	done
cleanAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
gAdd:
	@echo $(CYAN) && git add $(PROJECT_ROOT)
gCommit:
	@echo $(GREEN) && git commit -e || \
	if [ $$? -ne 0 ]; then \
		echo $(RED) "Error in commit message"; \
		exit 1; \
	fi
gPush:
	@echo $(YELLOW) && git push || \
	if [ $$? -ne 0 ]; then \
		echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --show-current) || \
		if [ $$? -ne 0 ]; then \
			echo $(RED) "git push --set-upstream failed with error" $(E_NC); \
			exit 1; \
		fi \
	fi
git:
	@if [ -f "$(GIT_REPO)/Makefile" ] && [ -d "$(GIT_REPO)/.git" ]; then \
		$(MAKE) -C "$(GIT_REPO)" git; \
	else \
		$(MAKE) -C "$(PROJECT_ROOT)/$(CURRENT)" cleanAll gAdd gCommit gPush; \
	fi
quick: cleanAll
	@echo $(GREEN) && git commit -am "* Update in files: "; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		exit 1; \
	else \
		$(MAKE) -C . gPush; \
	fi
soft:
	@if [ -f "$(GIT_REPO)/Makefile" ]; then	\
		$(MAKE) -C $(GIT_REPO) soft || \
		if [ $$? -ne 0 ]; then \
		echo $(RED) GIT_REPO not found $(E_NC); \
	fi
cpp: # Usage: make cpp h=filename
	@if [ ! -d "include" ]; then \
		mkdir include; \
	fi
	@if [ ! -d "src" ]; then \
		mkdir src; \
		touch src/main.cpp; \
	fi
	@if [ ! -f "include/$(h)" ]; then \
		touch include/$(h); \
	fi
	@for file in include/*.hpp; do \
		if [ ! -f "src/$$(basename "$${file%.*}").cpp" ]; then \
			touch src/$$(basename "$${file%.*}").cpp; \
		else \
			echo "src/$$(basename "$${file%.*}").cpp"; \
		fi; \
	done
#--------------------COLORS----------------------------#
# For print
CL_BOLD  = \e[1m
RAN      = \033[48;5;237m\033[38;5;255m
NC       = \033[m
P_RED    = \e[1;91m
P_GREEN  = \e[1;32m
P_BLUE   = \e[0;36m
P_YELLOW = \e[1;33m
P_CCYN   = \e[0;1;36m
P_NC     = \e[0m
LF       = \e[1K\r$(P_NC)
FG_TEXT  = $(P_NC)\e[38;2;189;147;249m
# For bash echo
CLEAR  = "\033c"
BOLD   = "\033[1m"
CROSS  = "\033[8m"
E_NC   = "\033[m"
RED    = "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
MAG    = "\033[1;35m"
CYAN   = "\033[0;1;36m"
GRAY   = "\033[1;90m"
BANNER = "$$CPP"
TRASH_BANNER = "$$TRASH"

define CPP

		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢟⡋⣇⠧⣹⢰⡛⡻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⡿⡟⣍⡚⢦⡹⣰⡙⢦⢣⢝⡸⡅⢯⡛⢿⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⢿⡋⢧⢣⠳⣌⣓⢣⡕⢦⡙⢮⢜⣊⠶⡙⢦⡹⢜⡪⢝⡻⣿⣿⣿⣿$(NC)
		$(RAN)⣿⢟⡍⢎⡖⠭⡎⣕⢫⡔⢮⣑⣪⣥⣿⣬⣶⣍⣖⡹⢆⡳⣩⢜⢣⢎⠵⣩⢛⢿$(NC)
		$(RAN)⣙⠲⡜⣣⢚⡵⢩⡒⣧⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣧⡱⢎⡣⢎⡳⠜⠘⠘$(NC)
		$(RAN)⣌⠳⣍⠖⣣⠎⣇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣋⠼⠁⠁⠀⠀⠀$(NC)
		$(RAN)⣌⠳⣬⡙⢦⣹⣿⣿⣿⣿⣿⢟⡛⢧⡹⠜⣜⠻⡻⣿⡿⠟⠋⠀⠀⠀⠀⠀⠀⠀$(NC)
		$(RAN)⣌⠳⡆⡝⢦⣽⣿⣿⣿⣿⠟⢦⡙⢦⡓⢽⡨⠓⠁⠉⠀⠀⠀⣀⠀⠀⠀⣀⠀⠀$(NC)
		$(RAN)⣌⢳⡩⢞⣡⣿⣿⣿⣿⣿⣙⢦⡙⠦⠙⠂⠁⠀⠀⠀⠀⠰⠶⣿⠶⠀⠶⣿⠶⠀$(NC)
		$(RAN)⣌⠳⣌⡓⢦⢻⣿⣿⣿⣿⣎⠒⠉⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠉⠀⠀⠀⠉⠀⠀$(NC)
		$(RAN)⣌⠳⣬⠹⣌⢻⣿⣿⣿⣿⣿⣦⣄⡀⠀⠀⠀⣀⣴⣿⣷⣦⣄⠀⠀⠀⠀⠀⠀⠀$(NC)
		$(RAN)⣌⠳⢆⡛⠌⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀$(NC)
		$(RAN)⡨⠋⠀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⢀$(NC)
		$(RAN)⣿⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠛⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⢀⣀⣴⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀⠀⠀⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(NC)

endef
export CPP

define TRASH

		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⡟⠻⠿⣛⡛⢿⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣶⣶⣬⣍⣙⢻⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⡇⠀⡄⢠⠀⡤⠀⣾⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣷⠀⡇⢸⠀⡇⠀⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⠀⣷⢸⠀⡇⢰⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣇⣈⣈⣀⣁⣼⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(NC)
		$(RAN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(NC)
endef
export TRASH