clear
while [ 1 ]
do 
	echo -e "\n1. New File  2. Display  3. Insert  4. Search  5. Modify  6. Delete  7. Exit"
	echo -n "Enter your option: "
	read ch

	case $ch in
	1)
		echo -n "Enter File name: "
		read fname
		if [ -e $fname ];then
			echo "File Already Exists"
		else
			touch $fname
			echo "File Created Successfull"
		fi
		;;
	2)
		echo -n "Enter file name: "
		read fname
		if [ -e $fname ]; then
			echo "The content of File: "
			sort -n $fname
		else 
			echo "File Not Exists"
		fi
		;;
	3)
		echo -n "Enter File name: "
		read fname
		if [ -e $fname ];then
			echo -n "Enter the Train Number: "
			read tno
			grep -w "$tno" $fname > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				echo "Record Already Present"
			else 
				echo -n "Enter Train name : "
				read tname
				echo $tno $tname >> $fname
				echo "Record Inserted Successfully"
			fi
		else 
			echo "File not Exists"
		fi
		;;
	4)
		echo -n "Enter File name: "
		read fname
		if [ -e $fname ];then
			echo -n "Enter the Train number to search: "
			read tno
			grep -w "$tno" $fname
			ans=$?
			if [ $ans -ne 0 ];then
				echo "Record not Found"
			fi	
		else
			echo "File don't Exists"
		fi
		;;
	5)
		echo -n "Enter the File name: " 
		read fname
		if [ -e $fname ]; then
			echo -n "Enter the Train number: "
			read tno
			grep -w "$tno" $fname > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				echo -n "Enter new Train number and Name: "
				read ntno ntname
				grep -w "$ntno" $fname > /dev/null
				ans2=$?
				if [ $ans2 -eq 0 ]; then
					echo "Record Already present, Please try another Train number"
				else
					grep -v "$tno" $fname > temp
					echo "$ntno $ntname" >> temp
					mv temp $fname
					echo "Record Modified successfully"
				fi
			else 
				echo "Record not Present"
			fi
		else 
			echo "File doesn't Exists"
		fi
		;;							
	6)
		echo -n "Enter the File name: "
		read fname
		if [ -e $fname ]; then
			echo -n "Enter the Train number: "
			read tno
			grep -w "$tno" $fname > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				grep -v "$tno" $fname > temp
				mv temp $fname
				echo "Record Deleted Successfully"
			else 
				echo "Record Doesn't Exists"
			fi
		else 
			echo "File Don't Exists"
		fi
		;;
	7)
			exit
			;;	
	*)
			echo "Wrong Input"
	esac
done
