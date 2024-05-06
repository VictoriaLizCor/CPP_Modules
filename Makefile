MAKEFLAGS			+= --no-print-directory
CURRENT				:= $(shell basename $$PWD)
ROOT_CPP_MODULES	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/)
DIRS				:= $(abspath $(dir ${shell find ./*/ -type d -name "CPP_0*"}))
#------ DEBUG ------#
D			= 0
#------ Sanitizer ------#+
S			= 0
#--------------------UTILS----------------------------#
# Called with -> make all D=1
all:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)$$(basename $$mod) $(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*"); do \
			$(MAKE) -C $$subdir D=$(D) re test; \
		done; \
	done

dirs:
	@echo ROOT_CPP_MODULES: $(CYAN) $(ROOT_CPP_MODULES) $(E_NC)
	@echo $(CURRENT)
	@echo $(DIRS)

gAdd:
	@echo $(CYAN) && git add $(ROOT_CPP_MODULES)

gCommit:
	@echo $(GREEN) && git commit -e

gtest:
	@ls x > /dev/null || \
	if [ $$? -ne 0 ]; then \
		echo $(RED) "Command failed" $(YELLOW); \
	fi
gPush:
	@echo $(YELLOW) && git push > /dev/null || \
	if [ $$? -ne 0 ]; then \
		echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --show-current); \
	fi
# @echo $(YELLOW) && git push > /dev/null || \
# (echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
# git push --set-upstream origin $(shell git branch --show-current))

cleanAll:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)*******************$$(basename $$mod)*******************$(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*"); do \
			$(MAKE) -C $$subdir fclean; \
		done; \
	done

git: cleanAll gAdd gCommit gPush
# make log m=style
mlog:
	@git log -10 --pretty=format:"'%h'%m%s {%cd}" --date=format:'%Y-%m-%d %H:%M' | \
	pygmentize -g -O  style=$$m | cut -d'|' -f1

plog:
	@git log -10 --pretty=format:"'%h'%m %s {%cd}" --date=format:'%Y-%m-%d %H:%M' |\
	pygmentize -g -O  style=material | cut -d'|' -f1
#	git log -4 --abbrev-commit --no-color | pygmentize -g -O style=material

quick:cleanAll gAdd
# git commit --amend --no-edit 
	@script -q /dev/null -c "git status --porcelain -b -s " > msg_template
	@git status --porcelain -b -s > msg_template
	@git commit -aF msg_template
	@rm msg_template
	$(MAKE) gPush

ghook:
	@echo $(GREEN) && \
	git commit -am "update in files: '$(shell git diff --name-only --diff-filter=M | paste -sd "," -)'"
	@echo $(YELLOW) && git push
# commit correction git commit --amend
# //avoid last commit message
soft:
	@echo && echo $(GREEN) "Last 10 commits:" $(E_NC)
	@$(MAKE) plog && echo 
	@read -p "Do you want to reset the last commit? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) git reset --soft HEAD~1; echo $(RED) "Last commit reset" $(E_NC) ;; \
		* ) echo $(YELLOW) "No changes made" $(E_NC) ;; \
	esac
template:
	@git config --local commit.template .settings/.gitmessage
pre-commit:
	cp .settings/prepare-commit-msg .git/hooks/
	chmod +x .git/hooks/prepare-commit-msg

# git reset --soft HEAD~1 undoes the last commit and leaves your
# files and staging area in the state they were in prior to the commit. This is
# useful if you made a commit prematurely and need to add more changes or modify
# the commit message.
.PHONY: gAdd gCommit gPush git gQuick fclean log norm test
#--------------------COLORS---------------------------#
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
FG_TEXT = $(P_NC)\e[38;2;189;147;249m

CLEAR = "\033c"
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
list:
	@ls -la ./*/*
# start: $(NAME)
# 	@echo $(GREEN)./$(NAME) $(arg) $(E_NC)
# 	$(if $(arg), -./$(NAME) $(arg), \
# 		@printf "Input Example: \n\t make val arg=\"2 410 200 200\"\n")
# val: $(NAME)
# 	@echo $(RED) $(VALGRIND) ./$(NAME) $(arg) $(E_NC)
# 	@$(if $(arg), -$(VALGRIND) ./$(NAME) $(arg), \
# 		@printf "Input Example: \n\t make val arg=\"2 410 200 200\"\n")
# hel: $(NAME)
# 	@echo $(BLUE) $(HELGRIND) ./$(NAME) $(arg) $(E_NC)
# 	@$(if $(arg), -$(HELGRIND) ./$(NAME) $(arg), \
# 		@printf "Input Example: \n\t make hel arg=\"2 410 200 200\"\n")
# leaks: $(NAME)
# 	@echo $(YELLOW) $(MAC_LEAKS) ./$(NAME) $(arg) $(E_NC)
# 	@$(if $(arg), -$(MAC_LEAKS) ./$(NAME) $(arg), \
# 		@printf "Input Example: \n\t make hel arg=\"2 410 200 200\"\n")

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
