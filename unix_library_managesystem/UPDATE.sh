OLD_IFS="$IFS"
answer=y
while [ "$answer" = y ];do
	new_status= ; new_bname= ; new_date=
	tput clear
	tput clear ; tput cup 3 5 ; echo "Enter the Titile/Author>_"
	read response
	grep -i "$response" ULIB_FILE > TEMP
	if [ -s TEMP ]
	then
		IFS=":"
		read title author category status bname date < TEMP
		tput cup 5 10
		echo "UNIX Library-${BOLD}UPDATESTATUSMODE${NORMAL}"
		tput cup 7 23 ; echo "Title: $title"
		tput cup 8 22 ; echo "Author: $author"
		case $category in
					[Tt][Bb] ) word=textbook ;; 
					[Ss][xy][Ss] ) word=system ;;
					[Rr][Ee][Ff] ) word=reference ;;
								*) word=undefined ;;
		esac
		tput cup 9 20 ;echo "Category: $word"
		tput cup 10 22 ;echo "Status: $status"
		if [ "$status" = "in" ]
		then
		new_status=out
		tput cup 11 18 ; echo "New status: $new_status"
		tput cup 12 14 ; echo "Checked out by:_"
		read new_bname
		new_date=`date "+%D"`
		tput cup 13 24 ; echo "Date: $new_date"
		else
			new_status=in
			tput cup 11 14;echo "Checked out by: $bname"
			tput cup 12 24 ; echo "Date: $date"
			tput cup 15 18 ; echo "New status: $new_status"
		fi
		grep -iv "$title:$author:$category:$status:$bname:$date" ULIB_FILE > TEMP
		mv TEMP ULIB_FILE
		echo "$title:$author:$category:$new_status:$new_bname:$new_date">>ULIB_FILE
		else
		tput cup 7 10 ; echo "$response not found"
		fi
		tput cup 16 10; echo "Any more to Update? (Y)es or (N)o>_"
		read answer
		case $answer in
		[Yy]* ) answer=y;;
			* ) answer=n;;
		esac
done
IFS="$OLD_IFS"
exit 0
