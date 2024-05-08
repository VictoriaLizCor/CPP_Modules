#alias ls='ls -CFGA' # for macOS
alias ls='ls --color=auto'
alias lpyg='pygmentize -L styles'
#alias pig='pygmentize -g -O style=rainbow_dash'
#alias subl='/opt/sublime_text/sublime_text'
alias pyg='pygmentize -g -O style=material'
alias glog='git log --abbrev-commit --no-color'
alias log='git log -4 --abbrev-commit --no-color | pygmentize -g -O style=material'
alias flog="git log -10 --pretty=format:'(%h)%m %s #%cd' --date=format:'%Y-%m-%d %H:%M'"
# removing the ~...~ from the log
alias plog='flog | awk "
{
    gsub(/~[^~]*~/, \" \")
    print
}" | pyg'
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
    gsub(/#[0-9\- :]+/, LBLUE \"&\" NO_COLOR)
    print
}"'

#alias clog='glg'
alias vs='open ~/.config/Code/User/settings.json'
alias bs='open ~/.bashrc' 
alias sb='source ~/.bashrc' 
#PS1='\[\033[1;36m\]\u\[\033[1;31m\]@\[\033[1;32m\]\h:\[\033[1;35m\]\w\[\033[1;31m\]\$\[\033[0m\] '
#PS1='\[\e[32m\][\[\e[m\]\[\e[31m\]\u\[\e[m\]\[\e[33m\]@\[\e[m\]\[\e[32m\]\h\[\e[m\]:\[\e[36m\]\W\[\e[m\]\[\e[32m\]]\[\e[m\]\[\e[32;47m\]\\$\[\e[m\] '

PS1='\[\e[32m\][\[\e[m\]\[\e[1;32m\]\u\[\e[m\]\[\e[1;31m\]@\[\e[m\]\[\e[1;33m\]\h\[\e[m\]:\[\e[1;36m\]\w\[\e[m\]\[\e[32m\]]\[\e[m\]\[\e[32m\]\\$\[\e[m\] '
#PS1="\e[0;31m[\u@\h \W]\$ \e[m"
#source /Users/lilizarr/.docker/init-bash.sh || true # Added by Docker Desktop
#export PATH=$HOME/.brew/bin:$PATH
#export PATH=/Users/lilizarr/.brew/bin:$PATH
export CURSUS="$HOME/42_Cursus"
export EVAL="$HOME/42_Cursus/Eval"
export PROMPT_DIRTRIM=2 
#material
#dracula
#zenburn
#vim
#monokai
