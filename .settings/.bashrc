#alias ls='ls -CFGA' # for macOS
export SHELL=/usr/bin/bash
export TERM=screen-256color
alias ls='ls --color=auto'
alias lpyg='pygmentize -L styles'
#alias pig='pygmentize -g -O style=rainbow_dash'
#alias subl='/opt/sublime_text/sublime_text'
alias pyg='pygmentize -g -O style=material'
alias glog='git log --abbrev-commit --no-color'
alias log='git log -4 --abbrev-commit --no-color | pygmentize -g -O style=monokai'
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
    gsub(/~[^~]*~/, \" \")
    gsub(/\[[^\]]+\]/, BDEFAULT \"&\n\" NO_COLOR)
    gsub(/📝[^:]+: /, LGREEN \"&\" NO_COLOR) 
    gsub(/\([a-f0-9]+\)/, YELLOW \"&\" NO_COLOR)
    gsub(/#[0-9\- :]+/, LBLUE \"\n\t\t\t\t\t&\" NO_COLOR)
    print
}"'

#alias clog='glg'
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
#PS1="\e[0;31m[\u@\h \W]\$ \e[m"
#source /Users/lilizarr/.docker/init-bash.sh || true # Added by Docker Desktop
#export PATH=$HOME/.brew/bin:$PATH
#export PATH=/Users/lilizarr/.brew/bin:$PATH
export CURSUS="$HOME/42_Cursus"
export EVAL="$HOME/42_Cursus/Eval"
export PROMPT_DIRTRIM=2 
#    pygmentize -g -O style=${!#}
#material
#dracula
#zenburn
#vim
#monokai

cpyg() {
	pygmentize -g -O style=${!#}

}
