#alias ls='ls -CFGA' # for macOS
# Makes shell as default in bash
export SHELL=/usr/bin/bash
#able to use colors in terminal
export TERM=screen-256color
## Adding python to bash path to use pip
if [[ ":$PATH:" != *":$HOME/.local/bin:"* ]]; then
    export PATH="$HOME/.local/bin:$PATH"
fi
#export PATH="$PATH:/path/to/visual-studio-code/bin"code
export FLATPAK_USER_DIR=~/.local/share/flatpak
alias ucode='flatpak run com.visualstudio.code'
#export PATH="$(python -m site --user-base)/bin:$PATH"
alias ls='ls --color=auto'
alias lpyg='pygmentize -L styles'
alias gs='git status'
alias gb='git branch -a'
alias cl='open $CURSUS/linux_commands.txt'
alias space='ncdu $HOME'
#alias pig='pygmentize -g -O style=rainbow_dash'
alias pyg='pygmentize -g -O style=material'
alias glog='git log --abbrev-commit --no-color'
alias log='git log -3 --abbrev-comcode -no-color | pygmentize -g -O style=material'
alias flog="git log -10 --pretty=format:'(%h)%m %s %b #%cd' --date=format:'%Y-%m-%d %H:%M'"
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

alias llog='git log -4 --pretty=format:"#%cd (%h) %B" --date=format:"%Y-%m-%d %H:%M"| awk "
BEGIN {
    RED=\"\033[0;31m\"
    YELLOW=\"\033[038;5;221m\"
    GREEN=\"\033[0;32m\"
    NO_COLOR=\"\033[0m\"
    LGREEN=\"\033[0;38;5;84m\"
    LBLUE=\"\033[0;38;5;103m\"
    BDEFAULT=\"\033[1;39m\"
    RETURN=\"\033[1A\r\"
    ignore=0
}
{
        gsub(/\[[^\]]+\]/, BDEFAULT \"&\" NO_COLOR)
        gsub(/\([a-f0-9]+\)/, YELLOW \"-----&----->\" NO_COLOR)
        gsub(/#[0-9\- :]+/, LBLUE \"&\" NO_COLOR)
        gsub(/📝[^:]+: /, LGREEN \"&\" NO_COLOR)
        gsub(/* [^:]+: /, LGREEN \"&\" NO_COLOR)
        gsub(/\] [^:]+: /, LGREEN \"&\" NO_COLOR) 
        gsub(/~[^~]*~/, RETURN \"\")
        print
}"'
alias vs='open ~/.config/Code/User/settings.json'
alias bs='open ~/.bashrc' 
alias sb='source ~/.bashrc'
alias st='open ~/.config/terminator/config'
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
#flatpak remote-ls --app
#flatpak list --app --columns=application
#flatpak uninstall --user --all
#flatpak remote-ls --app --columns=application | grep sublimetext
#flatpak info --show-deps com.sublimetext.three
#flatpak uninstall com.sublimetext.three
#flatpak uninstall com.visualstudio.code
#flatpak uninstall --user  org.freedesktop.Platform.GL.default
#flatpak uninstall --user  org.freedesktop.Platform.GL.default 
#flatpak install --user com.visualstudio.code
#flatpak install --user  runtime/org.freedesktop.Sdk/x86_64/21.08
#flatpak install --user flathub org.freedesktop.Sdk//21.08 -y
#flatpak install --user runtime/org.freedesktop.Sdk/x86_64/21.08
#APP_ID=$(flatpak remote-ls flathub --user --app --columns=application | grep sublimetext)
#flatpak remote-add --if-not-exists --user flathub https://flathub.org/repo/flathub.flatpakrepo 
#flatpak install --user --no-deps flathub "$APP_ID" -y

sublime()
{
	SYSTEM_PATH=$(find /var/lib/flatpak/app/ -name sublime_text -type f 2>/dev/null | head -n 1)
	if [ -z "$SYSTEM_PATH" ]; then 
		if [ -z "$(flatpak list --columns=application | grep sublimetext)" ]; then 
			echo "Sublime Text not found in System path: /var/lib/flatpak/app/"
			echo "Installing ..."
			ftpkg

		fi
		#USER_PATH=$(find $HOME/.local/share/flatpak/app -name sublime_text -type f 2>/dev/null | head -n 1)
		#echo "User path = $USER_PATH"
		#alias subl="$USER_PATH"
	else 
		alias subl="$SYSTEM_PATH"
	fi
}
sublime
#split_terminal() {
#    if [ -z "$TMUX" ]; then
#        # Not inside a tmux session, start a new session and split vertically
#        tmux new-session \; split-window -v
#    else
#        # Inside a tmux session, just split the current window vertically
#        tmux split-window -v
#    fi
#}
#creating a new tab
#dbus-send --type=method_call --dest=net.tenshu.Terminator20x1a6021154d881c /net/tenshu/Terminator2/Window1 net.tenshu.Terminator.Window.new_tab

br() {
    local display=$(xrandr | grep " connected" | awk '/eDP/{print $1}' | head -n 1)
    local step=0.1     # Adjust step size as needed
    local max_brightness=1.3
    local min_brightness=1
    local direction=$1  # Expected to be "m" for up or "l" for down

    # Get the current brightness
    local current_brightness=$(xrandr --verbose | grep "Brightness" | cut -d ' ' -f2)

    # Calculate new brightness based on direction
    new_brightness=$(echo "$current_brightness + $step" | bc)

    # Adjust brightness based on thresholds
    if (( $(echo "$new_brightness > $max_brightness" | bc -l) )); then
        new_brightness=$min_brightness
    elif (( $(echo "$new_brightness < $min_brightness" | bc -l) )); then
        new_brightness=$max_brightness
    fi

    # Set the new brightness
    xrandr --output $display --brightness $new_brightness
}

alias split='split_terminal'
alias cf="find . -name '*.cpp' -exec pygmentize -g -O style=material {} \;"
alias hf="find . -name '*.hpp' -exec pygmentize -g -O style=material {} \;"
alias e1="cd $ECPP; cd cpp05_lle-briq/ex02;"
alias e2="cd $ECPP; cd cpp_clemedon/module05/ex02;"