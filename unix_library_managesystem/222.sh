#! /bin/sh
BOLD=`tput smso`
NORMAL=`tput rmso`
export BOLD NORMAL

# 欢迎页面
tput clear
tput cup 5 35
printf "${BOLD}Super Duper UNIX Library\n"
tput cup 12 30
printf "${NORMAL}This is the UNIX library application\n"
tput cup 14 30
printf "Please enter any key to continue..."
read ANSWER     # 临时变量
#
error_flag=0
while true; do
    # 如果没有错误，显示主菜单
    if [ "$error_flag" = 0 ]; then
        tput clear
        tput cup 5 10
        printf "UNIX Library - ${BOLD}MAIN MENU${NORMAL}\n"
        tput cup 7 20
        printf "0. ${BOLD}EXIT${NORMAL} this program\n"
        tput cup 9 20
        printf "1. ${BOLD}EDIT${NORMAL} Menu\n"
        tput cup 11 20
        printf "2. ${BOLD}REPORTS${NORMAL} Menu\n"
        error_flag=0
    fi
    tput cup 13 10
    printf "Enter your choice >"
    read CHOICE     # 用户选择

    # 根据选择执行脚本
    case $CHOICE in
        0) tput clear; exit 0;;
        1) ./edit.sh;;
        2) ./reports.sh;;
        *) ./error.sh 20 10; 
        tput cup 20 1; tput ed; 
        error_flag=1;;
    esac
done

exit 0
