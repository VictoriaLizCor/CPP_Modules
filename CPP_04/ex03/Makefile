#------ TARGET ------#
NAME		:= $(notdir $(CURDIR))
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 -Wshadow -Werror #-Wno-unused-function -Wunused
INCLUDES	+= -I include/
#------ SRC FILES & DIRECTORIES ------#
SRC_DIR		:= src/
SRC			:= $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')
MAIN		:= $(shell find $(SRC_DIR) -name 'main.cpp')
SRC			+= $(MAIN)
PROJECT_ROOT:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../)
GIT_REPO	:=$(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
DIRS		:= $(abspath $(dir $(shell find $(PROJECT_ROOT) -name Makefile | sort)))
CURRENT		:= $(shell basename $$PWD)
DEBUG_PATH	:= debug
#------ DEBUG FLAG ------#
D			= 0
#------ Sanitizer Flag ------#
S			= -1
#------ DEBUG UTILS ------#
CXX			:= c++
MAKEFLAGS	+= --no-print-directory #--jobs
VALGRIND	:= valgrind -s --leak-check=yes --show-leak-kinds=all -q 
HELGRIND	:= valgrind -s --tool=helgrind
MAC_LEAKS	:= leaks -atExit --


#------ ADDING DEBUG FLAGS ------#
ifneq ($(D), 0)
BUILD_DIR	:= .build/
DEBUG_DIR	:= $(NAME).dSYM
CXX			= g++
OBJS := $(addprefix $(BUILD_DIR), $(notdir $(SRC:%.cpp=%.o)))
#------ CODE FOR OBJECT FILES ------#
# The `vpath` directive in a Makefile is used to specify a list of directories
# that `make` should search when it's looking for prerequisites.
vpath %.cpp $(sort $(dir $(SRC)))
DEPS		:= $(OBJS:.o=.d)
DEPENDENCIES := $(shell find $(BUILD_DIR) -name '*.d')
-include $(DEPS) # to include in compilation
D_FLAGS		+= -O0 -g3 #-Og optimization + good debuggin experience
# ASAN_OPTIONS=detect_leaks=1 # in case platform leaks detections is not enable
# DEBUG_SRC	:= $(shell find $(DEBUG_PATH) -name '*.cpp')
# SRC			+= $(DEBUG_SRC)
# INCLUDES	+= -I $(DEBUG_PATH)/include
DEBUG_FLAG	:= $(D)
ifeq ($(DEBUG_FLAG),)
D_FLAGS		+= -DDEBUG=1
else
D_FLAGS		+= -DDEBUG=$(D)
endif
D_FLAGS		+= -Wconversion -Wsign-conversion -pedantic
D_FLAGS		+= -fno-omit-frame-pointer
# else
# MAIN		:= $(SRC_DIR)main.cpp
# SRC			+= $(MAIN)
else
OBJS		:= $(SRC)
endif
# MAKEFLAGS	+= -j4 #--debug
ifeq ($(S), 1)
#------ INCLUDE SANATIZER FLAGS ------#
D_FLAGS		+= -fsanitize=address,undefined,vptr
endif
# To enable verbose output during compilation Make V=1
V ?= 0
ifeq ($(V),1)
VERBOSE = @
D_FLAGS		+= -ftime-report
else
VERBOSE =
endif
#-------------------- RULES ----------------------------#
all:$(NAME)

$(NAME): $(OBJS)
ifneq ($(D), 0)
	@printf "$(LF)\n$(P_BLUE)☑️  Successfully Created $(P_YELLOW)$(NAME)'s Object files ☑️$(FG_TEXT)\n"
endif
	@printf "\n"
	@printf "$(LF)⚙️ $(P_BLUE) Create $(P_GREEN)$@ ⚙️\n"
	@echo $(GREEN)
	@printf "$(CXX) $(D_FLAGS) $(INCLUDES) $(P_YELLOW) $^ $(P_GREEN) -o $@ $(FG_TEXT) \n\n";
	@$(CXX) $(D_FLAGS) $(INCLUDES) $^ -o $(NAME)
	@printf "\n$(LF)✅ $(P_BLUE)Successfully Created $(P_GREEN)$@! ✅\n$(P_NC)"
	@echo $(CYAN) "$$CPP" $(E_NC)
	@echo "$$MANUAL" $(E_NC)

ifneq ($(D), 0)
$(OBJS): $(BUILD_DIR)%.o : %.cpp | $(BUILD_DIR)
	@$(CXX) $(D_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "$(LF)🚧 $(P_BLUE)Creating $(P_YELLOW)$@ $(P_BLUE)from $(P_YELLOW) $< $(FG_TEXT)"

$(BUILD_DIR):
	@mkdir -p $@
endif

.PHONY: clean fclean re test val leaks

clean:
	@echo $(RED)
	@if [ -d "$(BUILD_DIR)" ]; then	\
		rm -rf $(BUILD_DIR); 		\
		printf "$(LF)🧹 $(P_RED) Clean $(P_YELLOW)$(NAME)'s Object files$(P_NC)\n"; \
	fi
	@if [ -d "$(DEBUG_DIR)" ]; then	\
		rm -rf $(DEBUG_DIR); 		\
	fi
	@printf  "\n$(P_NC)"

fclean: clean
	@if [ -f "$(NAME)" ]; then	\
		printf "$(LF)🧹 $(P_RED) Clean $(P_GREEN) $(CURRENT)/$(NAME)\n";	\
		rm -rf $(NAME);														\
		echo $(WHITE) "$$TRASH" $(E_NC);													\
	else																	\
		printf "$(LF)🧹$(P_RED) Clean $(P_GREEN) $(CURRENT)\n";			\
	fi
	@printf "\n$(P_NC)"

re: fclean all

#------------- TEST UTILS -----------------------------------#
#make check f=file
check:
	@g++ $(D_FLAGS) $(INCLUDES) -fsyntax-only $(f)
# make D=1 checkMain
#includeFiles="include/Ice.hpp include/Cure.hpp include/AMateria.hpp include/stringUtils.hpp"
#Use: make D=0 S=0 i=1 checkMain;
checkMain:
	@includeFiles="include/Ice.hpp include/Cure.hpp include/ICharacter.hpp include/Character.hpp include/AMateria.hpp include/stringUtils.hpp" ; \
	cpp_files=""; \
	for file in $$includeFiles; do \
		cpp_file="src/$$(basename $${file%.*}).cpp"; \
		if [ -f $$cpp_file ]; then \
			cpp_files="$$cpp_files $$cpp_file"; \
		fi; \
	done ; \
	cpp_files="$$cpp_files $(MAIN)" ; \
	printf "\n$(P_GREEN) $(CXX) $(D_FLAGS) $(INCLUDES) $(P_YELLOW) $$cpp_files $(P_GREEN) -o ex03 $(FG_TEXT)" ; echo; \
	$(CXX) $(D_FLAGS) $(INCLUDES) $$cpp_files -o ex03; \
	echo $(E_NC); $(MAKE) -C . test;

test:$(NAME)
	@echo $(BOLD) $(CYAN) ./$(NAME) $$i $(E_NC) "\n"
	@if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val; \
	else \
		echo $(E_NC); ./$(NAME) $$i; \
	fi
# ATTENTION !!!!!!!!!!!!!!  USE WITH S=0 !
leaks: $(NAME)
	@echo $(RED)$(MAC_LEAKS) ./$(NAME) "$i" $(E_NC)  "\n"
	@$(MAC_LEAKS) ./$(NAME)
	@echo "\n"

val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) "$i" $(E_NC) "\n"
	@$(VALGRIND) ./$(NAME) $$i; echo

# #-------------------- GIT UTILS ----------------------------#
info:
	@echo GIT_REPO:  $(CYAN) $(GIT_REPO) $(E_NC)
	@echo PROJECT_ROOT: $(CYAN) $(PROJECT_ROOT) $(E_NC)
	@echo DIRS: $(BOLD) $(DIRS) "\n" $(E_NC)
	@echo CURRENT: $(GREEN) $(CURRENT) $(E_NC)
	@echo SRC: $(YELLOW) $(SRC) $(E_NC)
	@echo OBJS: $(GRAY) $(OBJS) $(E_NC)
	@echo $(BLUE)"\nD = $(D)" $(E_NC)
	@echo $(BLUE)"S = $(S)" $(E_NC)
	@echo $(BLUE)"V = $(V)" $(E_NC)
	@echo $(BLUE)"DEPENDENCIES =" $(DEPENDENCIES) $(E_NC)
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
	@echo $(GREEN) && git commit -e ; \
	ret=$$?; \
		echo $(RED) "Error in commit message"; \
		exit 1; \
	fi
gPush:
	@echo $(YELLOW) && git push ; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
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
temp:
	@printf '%b\n' "$${MAIN_CONTENT}\n" | pygmentize -l cpp
	@printf '%b\n' "$${HEADER_CONTENT}\n" | pygmentize -l cpp
	@printf '%b\n' "$${CPP_CONTENT}\n" | pygmentize -l cpp
cpp: # Usage: make cpp h=filename
	@if [ ! -d "include" ]; then \
		mkdir include; \
	fi
	@if [ ! -z "$(h)" ] && [ ! -f "include/$(h).hpp" ]; then \
		UPPER_H=$$(echo $(h) | tr a-z A-Z)_HPP; \
		HEADER_PATH="include/$(h).hpp"; \
		printf "$${HEADER_CONTENT}" | sed -e 's/{{UPPER_H}}/'"$$UPPER_H"'/' \
		-e 's/{{CLASS_NAME}}/$(h)/g' > $$HEADER_PATH; \
		echo "$$HEADER_PATH was created"; \
	fi
	@if [ ! -d "src" ]; then \
		mkdir src; \
	fi
	@for file in include/*.hpp; do \
		cpp_file="src/$$(basename "$${file%.*}").cpp"; \
		if [ ! -f "$$cpp_file" ]; then \
			class_name="$$(basename "$${file%.*}")"; \
			echo "$${CPP_CONTENT}" | sed -e "s/{{CLASS_NAME}}/$$class_name/g" > "$$cpp_file"; \
			echo "$$cpp_file was created"; \
		fi; \
	done
	@echo "Recently Created/Modified files:"; find . -type f \( -name "*.cpp" -o -name "*.hpp" \) -mmin -5 | sort -r
content:
	@find . -type f \( -name "*.cpp" -o -name "*.hpp" \) | sort
main:
	@if [ ! -f "src/main.cpp" ]; then \
		printf "$${MAIN_CONTENT}" > src/main.cpp; \
		echo "src/main.cpp was created"; \
	fi
#	find . -type f \( -name "*.hpp" ! -name "stringUtils.hpp" \) -exec basename {} \;

#--------------------COLORS----------------------------#
# For print
CL_BOLD  = \e[1m
RAN	 	 = \033[48;5;237m\033[38;5;255m
D_PURPLE = \033[1;38;2;189;147;249m
D_WHITE  = \033[1;37m
NC	  	 = \033[m
P_RED	 = \e[1;91m
P_GREEN  = \e[1;32m
P_BLUE   = \e[0;36m
P_YELLOW = \e[1;33m
P_CCYN   = \e[0;1;36m
P_NC	 = \e[0m
LF	   = \e[1K\r$(P_NC)
FG_TEXT  = $(P_NC)\e[38;2;189;147;249m
# For bash echo
CLEAR  = "\033c"
BOLD   = "\033[1m"
CROSS  = "\033[8m"
E_NC   = "\033[m"
RED	= "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
WHITE  = "\033[1;37m"
MAG	= "\033[1;35m"
CYAN   = "\033[0;1;36m"
GRAY   = "\033[1;90m"
PURPLE = "\033[1;38;2;189;147;249m"
MANUAL = "$$MANUAL"
CPP    = "$$CPP"

define CPP

			⠀⠀⠀⠀⠀⠀⢀⣠⣴⣻⣽⣻⢦⣄⡀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⣀⣤⢶⣻⡽⣞⣧⢷⢯⣟⡾⣽⣳⣤⣀⠀⠀⠀
			⣠⣴⣞⣯⢯⣟⣧⠿⠙⠚⠛⠛⠊⠟⡷⣽⣞⣽⡻⣦⣄
			⣟⡾⣽⡺⣟⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⣞⣷⣻⣷⣿
			⣯⣟⡾⣽⠁⠀⠀⢀⡴⣖⣶⣲⢦⡀⣀⣴⣾⣿⣿⣿⣿
			⣷⣿⣿⡇⠀⠀⠀⣾⣿⣿⣶⣿⣿⣿⣿⣿⢻⣿⣿⢻⣿
			⣯⢿⡽⡃⠀⠀⠀⢷⣯⣿⣿⣿⣿⣿⣿⣶⣰⣾⣶⣰⣾
			⣯⢷⣻⡽⡀⠀⠀⠈⠻⠿⠿⠿⠟⠁⠉⠻⢿⣿⣿⣿⣿
			⣯⣟⣷⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿
			⠙⠻⢿⣿⣿⣿⣿⣶⣤⣤⣤⣤⣤⣶⣿⣿⣿⣿⡿⠟⠋
			⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀

endef
export CPP

define TRASH

			⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⣰⣾⠋⠙⠛⣿⡟⠛⣿⣿⣿⣷⣆⠀⠀⠀⠀
			⠀⠀⢠⣾⣿⣿⣷⣶⣤⣀⡀⠐⠛⠿⢿⣿⣿⣷⡄⠀⠀
			⠀⢠⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⠶⠦⠤⢠⣿⣿⣿⡄⠀
			⠀⣾⣿⣿⣿⣿⠀⣤⡀⠀⣤⠀⠀⣤⠀⢸⣿⣿⣿⣷⠀
			⠀⣿⣿⣿⣿⣿⠀⢿⡇⠀⣿⠀⢠⣿⠀⣿⣿⣿⣿⣿⠀
			⠀⢿⣿⣿⣿⣿⡄⢸⡇⠀⣿⠀⢸⡏⠀⣿⣿⣿⣿⡿⠀
			⠀⠘⣿⣿⣿⣿⡇⢸⡇⠀⣿⠀⢸⡇⢠⣿⣿⣿⣿⠃⠀
			⠀⠀⠘⢿⣿⣿⡇⢸⣧⠀⣿⠀⣼⡇⢸⣿⣿⡿⠁⠀⠀
			⠀⠀⠀⠀⠻⢿⣷⡘⠛⠀⠛⠀⠸⢃⣼⡿⠟⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀
endef
export TRASH

define MANUAL
$(D_PURPLE)
FLAGS:
	D -> debug information     (default: 0)
	S -> sanatizer information (default: -1)
	i -> switch case 
		* 1.- Character
		* 2.- AMateria
		* 3.- MateriaSource
		* 4.- ICharacter
		* Defautl Subject

Example:

$(D_WHITE)[show character test]
$(D_PURPLE)$> make test i=1
$(D_WHITE)[show debug information and run character test with valgrind]
$(D_PURPLE)$> make D=1 S=0 re test i=1
$(D_WHITE)[run subject test]
$(D_PURPLE)$> make test

endef
export MANUAL

define HEADER_CONTENT
#ifndef {{UPPER_H}}
# define {{UPPER_H}}

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class {{CLASS_NAME}}
{
	private:

	protected:
		
	public:
		{{CLASS_NAME}}();
		virtual ~{{CLASS_NAME}}(void);

};

// std::ostream& operator << (std::ostream& os, {{CLASS_NAME}}& rhs);

#endif // {{UPPER_H}}
endef
export HEADER_CONTENT
define MAIN_CONTENT
$(shell for file in include/*.hpp; do \
	printf '#include "'$$(basename $$file)'"\\n';\
done)
#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	return (0);
}

#endif
endef
export MAIN_CONTENT

define CPP_CONTENT
#include "{{CLASS_NAME}}.hpp"

{{CLASS_NAME}}::{{CLASS_NAME}}()
{
}

{{CLASS_NAME}}::~{{CLASS_NAME}}(void)
{
}

std::ostream& operator << (std::ostream& os, {{CLASS_NAME}}& rhs)
{
	return (os);
}
endef
export CPP_CONTENT
