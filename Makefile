MAKEFLAGS			+= --no-print-directory
GIT_REPO				:= $(shell basename $$PWD)
ROOT_CPP_MODULES	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/)
DIRS				:= $(abspath $(dir ${shell find ./*/ -type d -name "CPP_04*" |sort}))
# DIRS				:= $(abspath $(dir ${shell find ./*/ -type d -name "CPP_0*" |sort}))
#------ DEBUG ------#
D			= 1
#------ Sanitizer ------#+
S			= 0
#--------------------UTILS----------------------------#
# Called with -> make all D=1
all:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)$$(basename $$mod) $(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*" | sort); do \
			echo $(MAG) "\n$(MAKE) -C $$subdir D=$(D) re test" $(E_NC); \
			$(MAKE) -C $$subdir D=$(D) re test; \
			r=$$?; \
			if [ $$r -ne 0 ]; then \
				echo $(RED) "ERROR in $$subdir" $(E_NC); \
			fi \
		done; \
	done

allVal:
	@for mod in $(DIRS); do \
		echo "\n"$(BLUE)$$(basename $$mod) $(E_NC) ; \
		for subdir in $$(find $$mod -type d -name "ex0*" | sort); do \
			echo $(MAG) "\n$(MAKE) -C $$subdir D=$(D) re test" $(E_NC); \
			$(MAKE) -C $$subdir D=$(D) re val; \
			r=$$?; \
			if [ $$r -ne 0 ]; then \
				echo $(RED) "ERROR in $$subdir" $(E_NC); \
			fi \
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
	done;
gAdd:
	@echo $(CYAN) && git add $(ROOT_CPP_MODULES)
gCommit:
	@echo $(GREEN) && git commit -e ; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		echo $(RED) "Error in commit message"; \
		exit 1; \
	fi
gPush:
	@echo $(YELLOW) && git push ; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		echo $(RED) "git push failed, setting upstream branch\n" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --show-current) || \
		if [ $$? -ne 0 ]; then \
			echo $(RED) "git push --set-upstream failed with error" $(E_NC); \
		fi \
	fi
# @echo $(YELLOW) && git push > /dev/null || \
# (echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
# git push --set-upstream origin $(shell git branch --show-current))
#make DIRS=$CPP/CPP_0* cleanAll
git: cleanAll gAdd
	@$(MAKE) -C . gCommit; \
	ret=$$?; \
	if [ $$ret -ne 0 ]; then \
		exit 1; \
	else \
		$(MAKE) -C . gPush; \
	fi

mlog:
	@git log -5 --pretty=format:"'%h'%m%s {%cd} %b" --date=format:'%Y-%m-%d %H:%M' | \
	pygmentize -g -O  style=$$m | cut -d'|' -f1
plog:
	@git log -5 --pretty=format:"{%cd} (%h) %m %B" --date=format:'%Y-%m-%d %H:%M' |\
	pygmentize -g -O  style=material

quick: cleanAll
	@echo $(GREEN) && git commit -am "* Update in files: "; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		exit 1; \
	else \
		$(MAKE) -C . gPush; \
	fi
#$(shell git diff --name-only --diff-filter=M | awk 'NR > 1 {print prev","} {prev=$$0} END {print $0}')"
# Avoid last commit message
soft:
	@echo $(GREEN) "\nLast 10 commits:" $(E_NC)
	@$(MAKE) plog && echo 
	@read -p "Do you want to reset the last commit? (y/n) " yn; \
	case $$yn in \
		[Yy]* ) git reset --soft HEAD~1;\
		git push origin --force-with-lease $(shell git branch --show-current) ;\
		echo $(RED) "Last commit reset" $(E_NC) ;; \
		* ) echo $(MAG) "No changes made" $(E_NC) ;; \
	esac
amend:
	@echo $(CYAN) && git commit --amend; \
	result=$$?; \
	if [ $$result -ne 0 ]; then \
		echo $(RED) "The amend commit message was not modified."; \
		exit 1; \
	else \
		echo $(YELLOW) && git push origin --force-with-lease $(shell git branch --show-current); \
		exit 0; \
	fi
template:
	@git config --local commit.template .settings/.gitmessage
pre-commit:
	cp .settings/prepare-commit-msg .git/hooks/
	chmod +x .git/hooks/prepare-commit-msg
commit-msg:
	cp .settings/commit-msg .git/hooks/
	chmod +x .git/hooks/commit-msg
post-merge:
	cp .settings/post-merge .git/hooks/
	chmod +x .git/hooks/post-merge
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
#------------- TEST UTILS -----------------------------------#
list:
	@ls --color=auto -Rla $(DIRS)

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
