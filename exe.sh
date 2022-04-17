#!/bin/sh

START="\033[0"
END="m"

BLINK="$START;3;5$END"
HIGHLIGHT_WARN="$START;1;3;4;33$END"
RESET="$START$END"

DESCRIPTION="This script will change information from commit history..."

while true; do
    printf "%18s$BLINK$DESCRIPTION$RESET\rwait 5 seconds. " " "
    sleep 1
    printf "\r${HIGHLIGHT_WARN}[!! CAUTION !!]$RESET "
    sleep 1
    printf "\rwait 3 seconds. "
    sleep 1
    printf "\r${HIGHLIGHT_WARN}[!! CAUTION !!]$RESET "
    sleep 1
    printf "\rwait 1 seconds. "
    sleep 1
    printf "\rImportant Notice: $DESCRIPTION\n"
    printf "Are you ${HIGHLIGHT_WARN}ABSOLUTELY SURE$RESET what you are doing exactly? [y/$START;4${END}N$RESET] > "
    read -r yn
    case $yn in
    "") echo "bye"; exit ;;
    [Nn]*) exit ;;
    [Yy]*) break ;;
    *) echo "Enter yes or no" ;;
    esac
done

git filter-branch -f --commit-filter '
if [ "$GIT_AUTHOR_NAME" = "신동빈" ];
then
    GIT_AUTHOR_NAME="Toysin";
    GIT_AUTHOR_EMAIL="toysin1203@hotmail.com";
    GIT_COMMITTER_EMAIL="toysin1203@hotmail.com";
    git commit-tree "$@";
else
    git commit-tree "$@";
fi' HEAD
