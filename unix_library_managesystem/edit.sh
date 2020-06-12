error_flag=0
while true;do
	if [ "$error_flag" = 0 ]
		then
		tput clear ; tput cup 5 10
		echo "UNIX Library - ${BOLD} EDITMENU ${NORMAL}"
		tput cup 7 20
		# place the cursor
		echo "0: ${BOLD}RETURN${NORMAL}To the Main Menu"
		tput cup 9 20 ; echo "1; ${BOLD}ADD${NORMAL}"
		tput cup 11 20 ; echo "2: ${BOLD}UPDATESTATUS${NORMAL}"
		tput cup 13 20 ; echo "3: ${BOLD}DISPLAY${NORMAL}"
		tput cup 15 20 ; echo "4: ${BOLD}DELETE${NORMAL}"
	fi
	error_flag=0
		# reset error f1ag
	tput cup 17 10 ; echo "Enter your choice>"
	read choice
# read user choice
# case construct for checking the user selection
	case $choice in
		0) exit 0;;
		# check user input
		1) ./ADD.sh;;
		# return to the mian menu
		2) ./UPDATE.sh;;
		# call UPDATE program
		3) ./DISPLAY.sh;;
		# cal1 DISPALY program
		4) ./DELETE.sh;;
		# call DELETE program
		*) ./error.sh 20 10;
		# call ERROR program
		tput cup 20 1 ;tput ed;
		# clear the rest of the screen
		error_flag=1;;
		# set error f1ag to indicate
	esac
# end of the case construct
done
exit 0