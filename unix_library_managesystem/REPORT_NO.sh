IFS=":"
case $1 in
    1 ) sort -f -d -t ':' -k 1 ULIB_FILE> TEMP ;;
    2 ) sort -f -d -t ':' -k 2 ULIB_FILE> TEMP ;;
    3 ) sort -f -d -t ':' -k 3 ULIB_FILE> TEMP ;;
esac
while read title author category status bname date
    do
    echo "Title: $title">> PTEMP
    echo "Author: $author">> PTEMP
    case $category in
        [Tt][Bb] ) word=textbook ;;
        [Ss][Yy][Ss] ) word=system ;;
        [Rr][Ee][Ff] ) word=reference ;;
    esac
    echo "Category: $word" >> PTEMP
    echo "Status: $status">> PTEMP
    if [ "$status" = "out" ]
        then
        echo " checked out by: $bname" >> PTEMP
        echo "Date: $date" >> PTEMP
    fi
    echo >> PTEMP
done < TEMP
#pg -c -P "Page %d:" PTEMP
cat PTEMP
read mykey
rm TEMP PTEMP
exit 0
