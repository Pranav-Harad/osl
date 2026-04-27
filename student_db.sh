#!/bin/bash
clear
while true
do 
	echo -e "\n1. New File  2. Display  3. Insert  4. Search  5. Modify  6. Delete  7. Exit"
	echo -n "Enter your option: "
	read ch

	case $ch in
	1)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ];then
			echo "File Already Exists"
		else
			touch "$fname"
			echo "File Created Successfully"
		fi
		;;
	2)
		echo -n "Enter file name: "
		read fname
		if [ -e "$fname" ]; then
			echo "The content of File: "
			sort -n "$fname"
		else 
			echo "File Not Exists"
		fi
		;;
	3)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ];then
			echo -n "Enter the Roll Number: "
			read Roll
			grep -w "^$Roll" "$fname" > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				echo "Record Already Present"
			else 
				echo -n "Enter name : "
				read name
				echo "$Roll $name" >> "$fname"
				echo "Record Inserted Successfully"
			fi
		else 
			echo "File not Exists"
		fi
		;;
	4)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ];then
			echo -n "Enter the Roll number to search: "
			read Roll
			grep -w "^$Roll" "$fname"
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
		if [ -e "$fname" ]; then
			echo -n "Enter the roll number: "
			read Roll
			grep -w "^$Roll" "$fname" > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				echo -n "Enter new Roll number and Name: "
				read nroll nname
				
				if [ "$nroll" != "$Roll" ]; then
					grep -w "^$nroll" "$fname" > /dev/null
					ans2=$?
				else
					ans2=1 # Skip the check if keeping the same roll number
				fi

				if [ $ans2 -eq 0 ]; then
					echo "Record Already present, Please try another roll number"
				else
					grep -v -w "^$Roll" "$fname" > temp
					echo "$nroll $nname" >> temp
					mv temp "$fname"
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
		if [ -e "$fname" ]; then
			echo -n "Enter the Roll number: "
			read Roll
			grep -w "^$Roll" "$fname" > /dev/null
			ans=$?
			if [ $ans -eq 0 ]; then
				grep -v -w "^$Roll" "$fname" > temp
				mv temp "$fname"
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
