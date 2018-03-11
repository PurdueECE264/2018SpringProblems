RESULT=result
name=result
make clean
rm $RESULT/${name}.txt
grade=0
for i in {1..7};
	do
	rm -f error.txt 
	echo "********************************************" >> $RESULT/${name}.txt
	echo "********************************************" >> $RESULT/${name}.txt
	make test${i} >> $RESULT/${name}.txt 2>error.txt
	if [ $? = "0" ]; then
		echo "Test Case "${i} "Passed" >> $RESULT/${name}.txt
		case ${i} in
			1 )
				let "grade+=5" ;;
			2 )
				let "grade+=25" ;;
			3 )
				let "grade+=30" ;;
			4 )
				let "grade+=10" ;;
			5 )
				let "grade+=10" ;;
			6 )
				let "grade+=10" ;;
			7 )
				let "grade+=10" ;;
		esac

	elif grep -q "124" error.txt; 
	then
		cat error.txt >> $RESULT/${name}.txt
		echo "Test Case "${i} "Timed out" >> $RESULT/${name}.txt
	else
		cat error.txt >> $RESULT/${name}.txt
		echo "Test failed: "${i} >> $RESULT/${name}.txt
		case ${i} in 
			3 )
				echo "Testing Part - 2 for Partition Function now" >> $RESULT/${name}.txt
				make test3a >> $RESULT/${name}.txt 2>error.txt
				if [ $? = "0" ]; then
					echo "Test Case "${i} "Passed" >> $RESULT/${name}.txt
					let "grade+=30"
				else
					echo "Test Case" ${i} "Part 2 Failed" >> $RESULT/${name}.txt
				fi
		esac
	fi
	echo " " >> $RESULT/${name}.txt
	echo "============================================= " >> $RESULT/${name}.txt
done
echo "Your Grade = "$grade
