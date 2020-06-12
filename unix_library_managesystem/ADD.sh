ANSWER=y
while [ "$ANSWER" = y ]; do
	tput clear
	tput cup 5 10 ; echo "UNIX Library - ${BOLD}ADDMODE"
	tput cup 7 23 ; echo "Tit1e:"
	tput cup 9 22 ; echo "Author:"
	tput cup 11 20 ; echo "Category:"
	tput cup 12 20 ; echo "sys; system, ref: reference, tb: textbook"
	echo "${NORMAL}"
	tput cup 7 30 ; read title
	tput cup 9 30 ; read author
	tput cup 11 30 ;read category
	status=in
	echo "$title:$author:$category:$status:$bname:$date">> ULIB_FILE
	tput cup 14 10 ;echo "Any more to add? (Y)es or (N)o>_"
	read ANSWER
	case $ANSWER in
		[Yy]* ) ANSWER=y;;
			* ) ANSWER=n;;
	esac
done
