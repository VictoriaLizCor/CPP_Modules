#------ TARGET ------#
NAME		:= 
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 -Werror
# INCLUDES	+= -I include/
#------ SRC FILES & DIRECTORIES ------#
# SRCS_DIR	:= src/
# SRCS		:=	
#------ DEBUG ------#
D			= 0
#------ Sanitizer ------#
S			= -1
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
D_FLAGS		+= -g++ -D DEBUG=$(D)
endif
ifeq ($(S), -1)
#MAKEFLAGS	+= --debug
OBJS		:= $(addprefix $(SRCS_DIR), $(SRCS))
else
#------CODE FOR OBJECT FILES------#
SRCS		:= $(SRCS:%=$(SRC_DIR)%)
OBJS		:= $(SRCS:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
DEPS		:= $(OBJS:.o=.d)
endif
#------ Include flags for Sanitizer ------#
ifeq ($(S), 1)
#D_FLAGS		+= -O0 -g3 -pthread -fsanitize=thread,undefined,integer -fno-optimize-sibling-calls
D_FLAGS		+= -O0 -g3 -pthread -fsanitize=thread,undefined -fno-optimize-sibling-calls
endif
ifeq ($(S), 0)
D_FLAGS		+= -O0 -g3 -pthread -fsanitize=address,undefined -fno-optimize-sibling-calls
endif

#------ RULES ------#
#all: $(NAME)   
$(NAME): $(OBJS)
ifneq ($(S), -1)
	@printf "$(LF)\n🚀 $(P_BLUE)Successfully Created $(P_YELLOW)$(NAME)'s Object files 🚀$(FG_TEXT)\n"
endif
	@printf "\n"
	@printf "$(LF)📚 $(P_BLUE)Create $(P_GREEN)$@ 📚\n"
	@echo $(GREEN)
	@printf "$(CC) $(D_FLAGS) $(INCLUDES) $^ -o $@ \n\n";
	@$(CC) $(D_FLAGS) $(INCLUDES) -pthread  $^ -o $(NAME)
	@printf "\n$(LF)🎉 $(P_BLUE)Successfully Created $(P_GREEN)$@! 🎉\n$(P_NC)"
	@echo $(PHILO_BANNER)

ifneq ($(S), -1)
$(OBJS): $(BUILD_DIR)%.o : $(SRCS_DIR)%.c | $(BUILD_DIR)
	@$(CC) $(D_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "$(LF)🚧 $(P_BLUE)Creating $(P_YELLOW)$@ $(P_BLUE)from $(P_YELLOW) $< $(FG_TEXT)"

$(BUILD_DIR):
	@mkdir -p $@
endif
clean:
	@echo $(RED)
	@if [ -d "$(BUILD_DIR)" ]; then	\
		rm -rf $(BUILD_DIR); 		\
		printf "$(LF)🧹🗑️ $(P_RED) Clean ($$PWD) $(P_YELLOW)$(NAME)'s Object files$(P_NC)\n"; \
	fi
	@if [ -d "$(DEBUG_DIR)" ]; then	\
		rm -rf $(DEBUG_DIR); 		\
	fi
	@printf  "\n$(P_NC)"

fclean:clean
		@printf "$(LF)🧹🗑️ $(P_RED) Clean ($$PWD) $(P_GREEN)$(NAME)\n"
		@rm -rf $(NAME)
		@echo $(TRASH_BANNER)
		@printf "\n$(P_NC)"

re: fclean all
# $(MAKE) fclean
# $(MAKE) all

.PHONY: all clean fclean re


#--------------------UTILS----------------------------#
git:fclean
	@echo $(CYAN) && git add ./
	@echo $(GREEN) && git commit -e
	@echo $(YELLOW) && git push
git2:fclean
	echo "toDo: \ndone:" >> msg_template 
#	@nano msg_template && sleep 2
#	@sleep 1
	@echo $(CYAN) && git add ./
	@echo $(GREEN) && git commit -F msg_template
	@pygmentize -g -O style=rainbow_dash msg_template > msg_template
	@echo $(YELLOW) && git push
com:fclean
	@script -q /dev/null -c "git status --porcelain -b -s " > tmp_commit_msg
	@echo $(CYAN) && git add ./
	@git commit -F tmp_commit_msg
	@rm tmp_commit_msg
	@echo $(YELLOW) && git push
#	git log -2
#git status --porcelain -b -s --column | cat

norm:
	@printf "$(P_GREEN)norminette ./src ./include $(NC)\n"
	@norminette ./src ./include | grep "Error" --color || echo $(GREEN)OK$(E_NC)

#--------------------COLORS----------------------------#
CL_BOLD = \e[1m
RAN = \033[48;5;237m\033[38;5;255m
NC = \033[m

P_RED = \e[1;91m
P_GREEN = \e[1;32m
P_BLUE = \e[0;34m
P_YELLOW = \e[1;33m
P_CCYN = \e[0;1;36m
P_NC = \e[0m
LF = \e[1K\r$(P_NC)
CRLF= \n$(LF)
FG_TEXT = $(P_NC)\e[38;2;189;147;249m

CROSS = "\033[8m"
RED = "\033[1;91m"
GREEN = "\033[1;32m"
BLUE = "\033[1;34m"
YELLOW = "\033[1;33m"
E_NC	= "\033[m"
CYAN = "\033[0;1;36m"
PHILO_BANNER = "$$PHILO"
TRASH_BANNER = "$$TRASH"

#------------- TEST UTILS -----------------------------------#
start: $(NAME)
	@echo $(GREEN)./$(NAME) $(arg) $(E_NC)
	$(if $(arg), -./$(NAME) $(arg), \
		@printf "Input Example: \n\t make val arg=\"2 410 200 200\"\n")
val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) $(arg) $(E_NC)
	@$(if $(arg), -$(VALGRIND) ./$(NAME) $(arg), \
		@printf "Input Example: \n\t make val arg=\"2 410 200 200\"\n")
hel: $(NAME)
	@echo $(BLUE) $(HELGRIND) ./$(NAME) $(arg) $(E_NC)
	@$(if $(arg), -$(HELGRIND) ./$(NAME) $(arg), \
		@printf "Input Example: \n\t make hel arg=\"2 410 200 200\"\n")
leaks: $(NAME)
	@echo $(YELLOW) $(MAC_LEAKS) ./$(NAME) $(arg) $(E_NC)
	@$(if $(arg), -$(MAC_LEAKS) ./$(NAME) $(arg), \
		@printf "Input Example: \n\t make hel arg=\"2 410 200 200\"\n")

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
