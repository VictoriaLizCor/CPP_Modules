MAKEFLAGS			+= --no-print-directory
GIT_REPO				:= $(shell basename $$PWD)
ROOT_CPP_MODULES	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/)
DIRS				:= $(abspath $(dir ${shell find ./*/ -type d -name "CPP_02*" |sort}))
#------ DEBUG ------#
D			= 0
#------ Sanitizer ------#+
S			= 0
#--------------------UTILS----------------------------#
# Called with -> make all D=1
all:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)$$(basename $$mod) $(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*" | sort); do \
			$(MAKE) -C $$subdir D=$(D) re test; \
		done; \
	done

cleanAll:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)*******************$$(basename $$mod)*******************$(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*" -exec test -e '{}/Makefile' ';' -print | sort); do \
			$(MAKE) -C $$subdir fclean; \
		done; \
	done

dirs:
	@echo ROOT_CPP_MODULES: $(CYAN) $(ROOT_CPP_MODULES) $(E_NC)
	@echo GIT_REPO: $(GREEN) $(GIT_REPO) $(E_NC)
	@echo DIRS: $(BOLD) $(DIRS) $(E_NC)
	@for subdir in $$(find $(DIRS) -type d -name "ex0*" | sort); do \
		echo "\t"$(GRAY) $$subdir $(E_NC); \
	done; \
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
		echo $(RED) "git push failed, setting upstream branch\n" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --show-GIT_REPO) || \
		if [ $$? -ne 0 ]; then \
			echo $(RED) "git push --set-upstream failed with error"; \
		fi; \
		echo $(E_NC); \
	fi
# @echo $(YELLOW) && git push > /dev/null || \
# (echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
# git push --set-upstream origin $(shell git branch --show-GIT_REPO))
#make DIRS=$CPP/CPP_0* cleanAll
git: cleanAll gAdd gCommit gPush
# make log m=style
mlog:
	@git log -5 --pretty=format:"'%h'%m%s {%cd}" --date=format:'%Y-%m-%d %H:%M' | \
	pygmentize -g -O  style=$$m | cut -d'|' -f1
plog:
	@git log -10 --pretty=format:"'%h'%m %s {%cd}" --date=format:'%Y-%m-%d %H:%M' |\
	pygmentize -g -O  style=material | cut -d'|' -f1
#	git log -4 --abbrev-commit --no-color | pygmentize -g -O style=material

# quick:cleanAll gAdd
# # git commit --amend --no-edit 
# 	@script -q /dev/null -c "git status --porcelain -b -s " > msg_template
# 	@git status --porcelain -b -s > msg_template
# 	@git commit -aF msg_template
# 	@rm msg_template
# 	$(MAKE) gPush

quick: cleanAll
	@echo $(GREEN) && \
	git commit -am "* Update in files: ' \
	$(shell git diff --name-only --diff-filter=M | paste -sd "," -)'"
	@echo $(YELLOW) && git push
# commit correction git commit --amend
# //avoid last commit message
soft:
	@echo && echo $(GREEN) "Last 10 commits:" $(E_NC)
	@$(MAKE) plog && echo 
	@read -p "Do you want to reset the last commit? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) git reset --soft HEAD~1;\
		git push origin --force-with-lease $(shell git branch --show-GIT_REPO) ;\
		echo $(RED) "Last commit reset" $(E_NC) ;; \
		* ) echo $(YELLOW) "No changes made" $(E_NC) ;; \
	esac
amend:
	@git commit --amend
	@echo $(YELLOW) && git push origin --force-with-lease $(shell git branch --show-GIT_REPO)
template:
	@git config --local commit.template .settings/.gitmessage
pre-commit:
	cp .settings/prepare-commit-msg .git/hooks/
	chmod +x .git/hooks/prepare-commit-msg
showcolors:
	@i=0; \
	while [ $$i -le 255 ]; do \
		printf "\e[1;38;5;$$i""m%3d " "$$i"; \
		if [ $$i -eq 15 ] || [ $$i -gt 15 -a `expr $$i - 15 % 6` -eq 0 ]; then \
			echo; \
		fi; \
		i=`expr $$i + 1`; \
	done
rgb:
	@for r in `seq 0 51 255`; do \
		for g in `seq 0 51 255`; do \
			for b in `seq 0 51 255`; do \
				printf "\e[1;38;2;$$r;$$g;$$b""m%3d,%3d,%3d " "$$r" "$$g" "$$b"; \
				echo; \
			done \
		done \
	done
colog:
	@git log origin $(shell git branch --show-GIT_REPO) -3
# cpp:
# 	@for file in includes/*.hpp; do \
# 		touch src/$$(basename "$${file%.*}").cpp; \
# 	done
# git reset --soft HEAD~1 undoes the last commit and leaves your
# files and staging area in the state they were in prior to the commit. This is
# useful if you made a commit prematurely and need to add more changes or modify
# the commit message.
.PHONY: gAdd gCommit gPush git gQuick fclean log norm test
#--------------------COLORS---------------------------#
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
# For bash echo
CLEAR = "\033c"
BOLD = "\033[1m"
CROSS = "\033[8m"
RED = "\033[1;91m"
GREEN = "\033[1;32m"
BLUE = "\033[1;34m"
YELLOW = "\033[1;33m"
E_NC	= "\033[m"
CYAN = "\033[0;1;36m"
GRAY = "\033[1;90m"
BANNER = "$$CPP"
TRASH_BANNER = "$$TRASH"
#------------- TEST UTILS -----------------------------------#
list:
	@ls -la ./*/*

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
