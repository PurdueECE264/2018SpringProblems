import subprocess
import sys
import datetime


def grade_file(expected_file,student_file,full_mark,num_of_lines):
		grade=0.0
		proc=subprocess.Popen("diff -w -i -U 0 "+ expected_file+" "+ student_file+" | grep ^- | wc -l", stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
		num_of_diff_lines, err = proc.communicate()
		if int(num_of_diff_lines)>0:
			num_of_diff_lines=int(num_of_diff_lines)-1

		proc=subprocess.Popen("diff -w -i -U 0 "+ expected_file+" "+ student_file+" | grep ^+ | wc -l", stdout=subprocess.PIPE, 		stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
		num_of_diff_lines2, err = proc.communicate()
		if int(num_of_diff_lines2)>0:
			num_of_diff_lines2=int(num_of_diff_lines2)-1
		
		num_of_diff_lines=int(num_of_diff_lines)+int(num_of_diff_lines2)

		grade =float(full_mark)-float((float(num_of_diff_lines)/num_of_lines)*full_mark)
		proc=subprocess.Popen("diff -w -i -U 0 "+ expected_file +" "+student_file, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		if grade <0:
			grade=0
		return (out,grade)







def main():
	proc=subprocess.Popen("cp ../main.c ./", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	
	proc=subprocess.Popen("cp ../pe10.c ./", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	comments=""
	tests = ["test1", "test2", "test3" , "test4","test5","test6"]
	commands= ["./pe10 20 2 2 > stest1.txt","./pe10 10 10 1 > stest2.txt","./pe10 19 5 3 > stest3.txt","./pe10 20 19 2 > stest4.txt","./pe10 100 5 2 > stest5.txt","./pe10 33 7 3 > stest6.txt"]
	linesNum=[9,9,6,9,49,10]
	
	
	
	print_grade=0.0
	no_Makefile_per=0.0
	total_grade=0.0
	late_hours=0
	test_grade=0.0
	# check if there is a makefile
	
		
#test PRINT
	proc=subprocess.Popen("touch main.c", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	int_compile_fault=False
	proc=subprocess.Popen("gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DJOSEPHUS pe10.obj2 main.c pe10.c -o pe10",stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	if out:
		int_compile_fault=True;
		comments=comments+"========Print() compile error========\n\nYour grade for this function out of 10 is:0\n"+out+"\n"
	else:
			
		proc=subprocess.Popen("./pe10 10 2 1 > sptest.txt", stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		if out:
			print_grade=0
			comments=comments+"========print()========\n\nYour grade for this function out of 10 is:0\n"+out+"\n"
		else:	
			arr,print_grade=grade_file("ptest","sptest.txt",10,9)
			comments=comments+"========print() ========\n\nYour grade for this function out of 10 is:"+repr(print_grade)+"\n\n"+arr+"\n"
		
				
		total_grade=total_grade+print_grade





	proc=subprocess.Popen("touch main.c", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	proc=subprocess.Popen("gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DPRINT pe10.obj1 main.c pe10.c -o pe10", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	if out:
		comments=comments+"========Josephus() compile error========\n\nYour grade for this function out of 90 is:0\n"+out+"\n"
	else:
		i=0
		while i < len(tests):
			proc=subprocess.Popen(commands[i], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
			out, err = proc.communicate()
			if out:
				test_grade=0
				comments=comments+"========Josephus() ========\n\nYour grade for this function out of 15 is:0\n"+out+"\n"
			else:	
				arr,test_grade=grade_file(tests[i],"s"+tests[i]+".txt",15,linesNum[i])
				comments=comments+"========Josephus() "+tests[i]+"========\n\nYour grade for this function out of 15 is:"+repr(test_grade)+"\n\n"+arr+"\n"
		
			i+=1
			total_grade=total_grade+test_grade

	


#Late		
	 
	

	comments="Your score out of 100 in this homework (HW10) : "+repr(total_grade)+"\n\n"+comments
		
		
	f=open("./Grade.txt","w")
	f.write(comments)
	print("Your grade fully explained in Grade.txt")
	

	
	



if __name__ == "__main__":
    main()

















