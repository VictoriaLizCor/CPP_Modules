#------ TARGET ------#
NAME		:= account
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 #-Werror
INCLUDES	+= -I includes/
#------ SRC FILES & DIRECTORIES ------#
SRC_DIR	:= src/
# SRC		:=	Contact.cpp			\
# 				Phonebook.cpp		\
# 				phonebookUtils.cpp		\
# 				stringUtils.cpp		\
# 				debug.cpp		\
# 				main.cpp
SRC			:= $(shell ls $(SRC_DIR) | grep .cpp$)
PROJECT_ROOT:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../)
GIT_REPO	:=$(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
CURRENT		:= $(shell basename $$PWD)
#------ DEBUG ------#
D			= 0
#------ Sanitizer ------#
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
D_FLAGS		+= -DDEBUG=$(D)
endif
ifeq ($(S), 0)
#MAKEFLAGS	+= --debug
OBJS		:= $(addprefix $(SRC_DIR), $(SRC))
else
#------ CODE FOR OBJECT FILES ------#
OBJS		:= $(SRC:%.cpp=$(BUILD_DIR)%.o)
DEPS		:= $(OBJS:.o=.d)
#------ INCLUDE SANATIZER FLAGS ------#
D_FLAGS		+= -O0 -g3 
D_FLAGS		+= -fsanitize=address,undefined
endif
#-------------------- RULES ----------------------------#
all: $(NAME)
$(NAME): $(OBJS)
ifneq ($(S), 0)
	echo $(OBJS)
	@printf "$(LF)\n🚀 $(P_BLUE)Successfully Created $(P_YELLOW)$(NAME)'s Object files 🚀$(FG_TEXT)\n"
endif
	@printf "\n"
	@printf "$(LF)📚 $(P_BLUE)Create $(P_GREEN)$@ 📚\n"
	@echo $(GREEN)
	@printf "$(CC) $(D_FLAGS) $(INCLUDES) $^ -o $@ \n\n";
	@$(CC) $(D_FLAGS) $(INCLUDES) -MMD -MP $^ -o $(NAME)
	@printf "\n$(LF)🎉 $(P_BLUE)Successfully Created $(P_GREEN)$@! 🎉\n$(P_NC)"
	@echo $(BANNER)
ifneq ($(S), 0)
$(OBJS): $(BUILD_DIR)%.o : $(SRC_DIR)%.cpp | $(BUILD_DIR)
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

re:     fclean all

.PHONY: all clean fclean re
#------------- TEST UTILS -----------------------------------#
test:$(NAME)
	@echo $(BOLD) $(CYAN) ./$(NAME) $(E_NC) "\n"
	@./$(NAME)
diff:$(NAME)
	@./$(NAME) > docs/test.log
	@sed 's/\[[^]]*\]//g' docs/test.log > temp1.log
	@sed 's/\[[^]]*\]//g' docs/intra.log > temp2.log
	@diff temp1.log temp2.log > /dev/null && echo $(GREEN)"same output"$(E_NC) || echo $(RED)"different output"$(E_NC)
	@read -p "Remove files? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) rm temp1.log temp2.log docs/test.log;; \
		* ) echo $(YELLOW) "No changes made" $(E_NC) ;; \
	esac
#echo $(RED) "Last commit reset" $(E_NC)
val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) $(E_NC)
	@$(VALGRIND) ./$(NAME)
leaks: $(NAME)
	@echo $(RED) $(MAC_LEAKS) ./$(NAME) $(E_NC)
	@$(MAC_LEAKS) ./$(NAME)
# #-------------------- GIT UTILS ----------------------------#
dirs:
	@echo $(PROJECT_ROOT)
	@echo $(GIT_REPO)
	@echo $(CURRENT)
gAdd:
	@echo $(CYAN) && git add $(PROJECT_ROOT)
gCommit:
	@echo $(GREEN) && git commit -e
gPush:
	@echo $(YELLOW) && git push
git:
	@ls -la $(GIT_REPO) | grep Makefile
	@if [ -f "$(GIT_REPO)/Makefile" ]; then	\
		$(MAKE) -C $(GIT_REPO) fclean gAdd gCommit gPush;		\
	else									\
		$(MAKE) -C $(PROJECT_ROOT) fclean gAdd gCommit gPush;	\
	fi
gQuick:fclean gAdd
	@git status --porcelain -b -s > $(GIT_REPO)/msg_template
	@git commit -F $(GIT_REPO)/msg_template
	@rm $(GIT_REPO)/msg_template
	$(MAKE) gPush
soft:
	@echo $(GREEN) "Last two commits:" $(E_NC)
	@git log -2
	@read -p "Do you want to reset the last commit? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) git reset --soft HEAD~1; echo $(RED) "Last commit reset" $(E_NC) ;; \
		* ) echo $(YELLOW) "No changes made" $(E_NC) ;; \
	esac
#--------------------COLORS----------------------------#
CL_BOLD = \e[1m
RAN = \033[48;5;237m\033[38;5;255m
NC = \033[m
P_RED = \e[1;91m
P_GREEN = \e[1;32m
P_BLUE = \e[0;36m
P_YELLOW = \e[1;33m
P_CCYN = \e[0;1;36m
P_NC = \e[0m
LF = \e[1K\r$(P_NC)
FG_TEXT = $(P_NC)\e[38;2;189;147;249m

BOLD = "\033[1m"
CROSS = "\033[8m"
RED = "\033[1;91m"
GREEN = "\033[1;32m"
BLUE = "\033[1;34m"
YELLOW = "\033[1;33m"
E_NC	= "\033[m"
CYAN = "\033[0;1;36m"
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