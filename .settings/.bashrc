#alias ls='ls -CFGA' # for macOS
# Makes shell as default in bash
export SHELL=/usr/bin/bash
#able to use colors in terminal
export TERM=screen-256color
## Adding python to bash path to use pip
export PATH="$(python -m site --user-base)/bin:$PATH"
alias ls='ls --color=auto'
alias lpyg='pygmentize -L styles'
alias gs='git status'
#alias pig='pygmentize -g -O style=rainbow_dash'
alias pyg='pygmentize -g -O style=material'
alias glog='git log --abbrev-commit --no-color'
alias log='git log -3 --abbrev-commit --no-color | pygmentize -g -O style=material'
alias flog="git log -10 --pretty=format:'(%h)%m %s #%cd' --date=format:'%Y-%m-%d %H:%M'"
alias plog='flog | awk "
{
    gsub(/\[[^\]]+\]/, \"&\n\")
    gsub(/~[^~]*~/, \" \")
    gsub(/#[0-9\- :]+/, \"\n\t\t\t\t\t&\")
    print
}" | pygmentize -g -O style=material'
alias ccut="cut -d'|' -f1"
#| fold -w 80
alias clog='flog | awk "
BEGIN {
    RED=\"\033[0;31m\"
    YELLOW=\"\033[038;5;221m\"
    GREEN=\"\033[0;32m\"
    NO_COLOR=\"\033[0m\"
    LGREEN=\"\033[0;38;5;84m\"
    LBLUE=\"\033[0;38;5;103m\"
    BDEFAULT=\"\033[1;39m\"
}
{
    gsub(/~[^~]*~/, \"\")
    gsub(/\[[^\]]+\]/, BDEFAULT \"&\n\" NO_COLOR)
    gsub(/\([a-f0-9]+\)/, YELLOW \"&\" NO_COLOR)
    gsub(/#[0-9\- :]+/, LBLUE \"\n\t\t\t\t\t&\" NO_COLOR)
    gsub(/📝[^:]+: /, LGREEN \"&\" NO_COLOR)
    gsub(/* [^:]+: /, LGREEN \"&\" NO_COLOR)
    gsub(/\] [^:]+: /, LGREEN \"&\" NO_COLOR) 
    print
}"'

alias llog='git log -4 --pretty=format:"#%cd (%h) %B " --date=format:"%Y-%m-%d %H:%M"| awk "
BEGIN {
    RED=\"\033[0;31m\"
    YELLOW=\"\033[038;5;221m\"
    GREEN=\"\033[0;32m\"
    NO_COLOR=\"\033[0m\"
    LGREEN=\"\033[0;38;5;84m\"
    LBLUE=\"\033[0;38;5;103m\"
    BDEFAULT=\"\033[1;39m\"
    RETURN=\"\033[1A\r\"
}
{
    gsub(/~[^~]*~/, RETURN \"\")
    gsub(/\[[^\]]+\]/, BDEFAULT \"&\" NO_COLOR)
    gsub(/\([a-f0-9]+\)/, YELLOW \"-----&----->\" NO_COLOR)
    gsub(/#[0-9\- :]+/, LBLUE \"&\" NO_COLOR)
    gsub(/📝[^:]+: /, LGREEN \"&\" NO_COLOR)
    gsub(/* [^:]+: /, LGREEN \"&\" NO_COLOR)
    gsub(/\] [^:]+: /, LGREEN \"&\" NO_COLOR) 
    sub(/\\n$/, \"\")
    print
}"'
alias vs='open ~/.config/Code/User/settings.json'
alias bs='open ~/.bashrc' 
alias sb='source ~/.bashrc'
alias st='open ~/.config/terminator/config'
#alias subl='SUB_PATH=$(find /var/lib/flatpak/app/com.sublimetext.three/x86_64/stable/ -name sublime_text -type f 2>/dev/null | head -n 1); if [ -z "$SUB_PATH" ]; then echo "Sublime Text not found"; else $("$SUB_PATH" "$@"); fi'

PS1='\[\e[32m\]'       # start green color
PS1+='['               # add [
PS1+='\[\e[m\]'        # reset color
PS1+='\[\e[1;32m\]\u'  # user name in bold green
PS1+='\[\e[m\]'        # reset color
PS1+='\[\e[1;31m\]@'   # @ in bold red
PS1+='\[\e[m\]'        # reset color
PS1+='\[\e[1;33m\]\h'  # host name in bold yellow
PS1+='\[\e[m\]'        # reset color
PS1+=':\[\e[1;36m\]\w' # current working directory in bold cyan
PS1+='\[\e[m\]'        # reset color
PS1+='\[\e[32m\]]'     # ] in green
PS1+='\[\e[m\]'        # reset color
PS1+='\[\e[32m\]\\$ '  # $ in green
PS1+='\[\e[m\]'        # reset color
#The command `export PROMPT_DIRTRIM=2` is a bash shell command that trims the directory path in the shell prompt to the last 2 directories when the path is too long to fit on one line.
export PROMPT_DIRTRIM=2 
#PS1="\e[0;31m[\u@\h \W]\$ \e[m"
#source /Users/lilizarr/.docker/init-bash.sh || true # Added by Docker Desktop
#export PATH=$HOME/.brew/bin:$PATH
#export PATH=/Users/lilizarr/.brew/bin:$PATH
export CURSUS="$HOME/42_Cursus"
export CPP="$CURSUS/CPP_Modules/"
export EVAL="$CURSUS/Eval"
export ECPP="$EVAL/CPP_modules/"
# use -> cat file | cpyg style_name
cpyg()
{
	pygmentize -g -O style=${!#}
}
# flatpak remote-ls --app
# flatpak list --app --columns=application
#flatpak remote-ls --app --columns=application | grep sublimetext
#flatpak uninstall com.sublimetext.three
sublime()
{
	SYSTEM_PATH=$(find /var/lib/flatpak/app/ -name sublime_text -type f 2>/dev/null | head -n 1)
	if [ -z "$SYSTEM_PATH" ]; then 
		if [ -z "$(flatpak list --columns=application | grep sublimetext)" ]; then 
			echo "Sublime Text not found in System path: /var/lib/flatpak/app/"
			echo "Installing ..."
			APP_ID=$(flatpak remote-ls flathub --user --app --columns=application | grep sublimetext)
			flatpak remote-add --if-not-exists --user flathub https://flathub.org/repo/flathub.flatpakrepo
			flatpak install --user flathub "$APP_ID" -y
		fi
		USER_PATH=$(find $HOME/.local/share/flatpak/app -name sublime_text -type f 2>/dev/null | head -n 1)
		#echo "User path = $USER_PATH"
		alias subl="$USER_PATH"
	else 
		alias subl="$SYSTEM_PATH"
	fi
}
sublime