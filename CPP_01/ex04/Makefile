#------ TARGET ------#
NAME		:= replace
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 -Werror
INCLUDES	+= -I includes/
#------ SRC FILES & DIRECTORIES ------#
SRC_DIR	:= src/
SRC			:= $(shell ls $(SRC_DIR) | grep .cpp$)
PROJECT_ROOT:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../)
GIT_REPO	:=$(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
DIRS		:= $(abspath $(dir ${shell find $(PROJECT_ROOT) -name Makefile}))
CURRENT		:= $(shell basename $$PWD)
FILE		:= docs/test.txt
S1S2	:= replace change
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
CC			= g++ -g
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
	@$(MAKE) delete to_remove=*Cpy*
	@$(MAKE) delete
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
long:
	$(eval TO_COPY=docs/longText)
	@$(MAKE) checkCpyFile FILE=$(TO_COPY) SHOW=true
	@sleep 1
# @$(MAKE) runTest arg="rabbit 'brave little rabbit'"
	@./$(NAME) $(TO_COPY) rabbit 'brave little rabbit'
empty:
	touch emptyFile
	ls -la emptyFile
	./$(NAME) emptyFile Harry Ha
modn: harry
	chmod 0000 funnyCpy
	ls -la funnyCpy
	./$(NAME) funnyCpy Ron Harry
modr: harry
	chmod 0444 funnyCpy
	ls -la funnyCpy
	./$(NAME) funnyCpy Ron Harry
modw: harry
	chmod 0222 funnyCpy
	ls -la funnyCpy
	./$(NAME) funnyCpy Ron Harry
modrw: harry
	chmod 0666 funnyCpy
	ls -la funnyCpy
	./$(NAME) funnyCpy Ron Harry
cat :
	@find . -name "*Cpy*" ! -name "*.replace*" -exec sh -c 'echo "\n---" {} "---"; cat {}' \;
	@find . -name "*.replace*" -exec sh -c 'echo "\n---" {} "---"; cat {}' \;
t1:harry
	./$(NAME) funnyCpy Ron Harry
	@$(MAKE) diff
t2:
	@echo $(BOLD) $(CYAN) ./$(NAME) funnyCpy Ron Harry $(E_NC) "\n"
	@./$(NAME) funnyCpy Ron Harry > /dev/null
checkCpyFile:
	@if [ -f "$(FILE)" ]; then	\
		FILE_NAME=$(notdir $(basename $(FILE))); \
		EXTENSION=$(suffix $(FILE)); \
		APPEND=Cpy; \
		NEW=$$FILE_NAME$$APPEND$$EXTENSION; \
		cp $(FILE) $$NEW;	\
		if [ -f $${NEW} ] && [ ! -z "$(SHOW)" ] || [ "$(SHOW)" = "false" ]; then \
			echo $(YELLOW) "Copied $(FILE) to $$NEW \n" $(E_NC);	\
		else \
			echo $$NEW; \
		fi \
	else	\
		echo $(RED) "$(FILE) does not exist" $(E_NC);	\
	fi
delete:
	@if [ ! -z "$(to_remove)" ]; then \
		find . -name "$(to_remove)" ! -name "*.replace*" -type f -exec rm -f {} \;; \
	else \
		find . -name "*.replace*" -type f -exec rm -f {} \;; \
	fi
harry:
	$(eval TO_COPY=docs/funny)
	@$(MAKE) checkCpyFile FILE=$(TO_COPY) SHOW=true
#	@sleep 1
#	@$(MAKE) runTest arg='Harry Ron'
# @$(MAKE) runTest > /dev/null; \
# if [ $$? -ne 0 ]; then \
# 	echo $(RED) "Command runTest failed" $(E_NC); \
# else \
# 	echo $(GREEN) "Command runTest successful" $(E_NC); \
# fi
file: clean
	$(eval TO_COPY=docs/test.txt)
	@$(MAKE) checkCpyFile FILE=$(TO_COPY) SHOW=true
	@sleep 1
	@$(MAKE) runTest arg='$(S1S2)'
# @$(MAKE) runTest > /dev/null | cat; \
# if [ $$? -ne 0 ]; then \
# 	echo $(RED) "Command runTest failed" $(E_NC); \
# else \git submodule deinit -f eval_repo
# 	echo $(GREEN) "Command runTest successful" $(E_NC); \
# fi
runTest:
	$(eval TMP = $(shell find . -name "*$(notdir $(TO_COPY))Cpy*" ! -name "*.replace*"))
	$(MAKE) test arg="$(TMP) $(arg)"
test:
	$(eval TEST_ARGS = $(if $(arg), $(arg),$(shell $(MAKE) checkCpyFile) $(S1S2)))
ifeq ($(D), 2)
	@echo $(BOLD) $(CYAN) Run in gdbgui dashboard:"\n" ./$(NAME) "$(TEST_ARGS)" $(E_NC) "\n"
	@gdbgui ./$(NAME)
else
ifeq ($(D), 1)
	@echo $(BOLD) $(CYAN) ./$(NAME) "$(TEST_ARGS)" $(E_NC) "\n"
	@./$(NAME) $(TEST_ARGS)
else
	@echo $(BOLD) $(CYAN) ./$(NAME) "$(TEST_ARGS)" $(E_NC) "\n"
	@./$(NAME) $(TEST_ARGS)
endif
endif
#	@$(MAKE) grep TEST_ARGS="$(TEST_ARGS)"
grep:
	@echo "------------------------------------------------"
	@grep --color $(word 2, $(TEST_ARGS)) $(word 1, $(TEST_ARGS)) && echo
	@if [ -f "$(word 1, $(TEST_ARGS)).replace" ]; then \
		grep --color '$(word 3, $(TEST_ARGS))' $(word 1, $(TEST_ARGS)).replace && echo ; \
		echo $(BLUE) DIFF $(E_NC); \
		diff $(word 1, $(TEST_ARGS)) $(word 1, $(TEST_ARGS)).replace || true && echo ; \
	fi
	@if [ -f "$(word 1, $(TEST_ARGS)).replace2" ]; then \
		grep --color "$(word 3, $(TEST_ARGS))" $(word 1, $(TEST_ARGS)).replace2 && echo  ; \
		diff $(word 1, $(TEST_ARGS)) $(word 1, $(TEST_ARGS)).replace2 || true ;echo ;\
	fi
#----
# @$(MAKE) delete to_remove=*Cpy* ;echo
#	@ls --color=auto
# testing functions used 
# nm -g /path/to/your/file | grep " T "
#pygmentize -g -O style=friendly $(word 1, $(TEST_ARGS)).replace && echo; \
############# USE WITH S=0
leaks: $(NAME)
	@echo $(RED)$(MAC_LEAKS) ./$(NAME) $(E_NC)  "\n"
	@$(MAC_LEAKS) ./$(NAME)
	@echo "\n"

val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) $(ARGS) $(E_NC) "\n"
	@$(VALGRIND) ./$(NAME) $(ARGS)
	@echo "\n"
## Diff with intra
diff:
	$(eval CPY= $(shell find . -name "*Cpy*" ! -name "*.replace*"))
	$(eval REPLACE= $(shell find . -name "*.replace*"))
	@if [ ! -s $(REPLACE) ]; then \
		echo;echo "$(REPLACE) is empty"; \
	else \
		echo $(YELLOW) "Diffing $(CPY) with $(REPLACE)" $(E_NC); \
		diff $(CPY) $(REPLACE) || true; \
	fi
# #-------------------- GIT UTILS ----------------------------#
dirs:
	@echo $(DIRS)
	@echo PROJECT_ROOT: $(CYAN) $(PROJECT_ROOT) $(E_NC)
	@echo GIT_REPO:  $(CYAN) $(GIT_REPO) $(E_NC)
	@echo $(CURRENT)
testAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir test; \
	done
cleanAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

gAdd:
	@echo $(CYAN) && git add $(PROJECT_ROOT)

gCommit:
	@echo $(GREEN) && git commit -e

gPush:
	@echo $(YELLOW) && git push > /dev/null || \
	if [ $$? -ne 0 ]; then \
		echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --SHOW-current); \
	fi

git:
	@if [ -f "$(GIT_REPO)/Makefile" ]; then	\
		$(MAKE) -C $(GIT_REPO) cleanAll gAdd gCommit gPush;		\
	else									\
		$(MAKE) -C $(PROJECT_ROOT)/$(CURRENT) cleanAll gAdd gCommit gPush;	\
	fi

quick:
	@echo $(GREEN) && \
	git commit -am "update in files: '$(shell git diff --name-only --diff-filter=M | paste -sd "," -)'"
	@echo $(YELLOW) && git push

soft:
	@echo $(GREEN) "Last two commits:" $(E_NC)
	@git log -2
	@read -p "Do you want to reset the last commit? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) git reset --soft HEAD~1; echo $(RED) "Last commit reset" $(E_NC) ;; \
		* ) echo $(YELLOW) "No changes made" $(E_NC) ;; \
	esac
cpp:
	@for file in includes/*.hpp; do \
		touch src/$$(basename "$${file%.*}").cpp; \
	done
gdbgui:
	@pip install gdbgui
#--------------------COLORS----------------------------#
# For print
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
# For bash
CLEAR = "\033c"
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