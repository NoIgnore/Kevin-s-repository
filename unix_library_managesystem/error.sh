tput cup $1 $2			# place the cursor on the screen
echo "Wrong Input. Try again."	# show the error message
printf "Press any key to continue...>" # display the prompt
read answer				# read user input
exit 0				# indicate normal exit
