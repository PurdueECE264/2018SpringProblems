import subprocess
import sys


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


def make():
	proc=subprocess.Popen("make", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	proc=subprocess.Popen("ls | grep pa08$", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out2, err2 = proc.communicate()
	if "pa08" in out2:
		return "NO ERROR"
	else:
		return out
def cmake():
	proc=subprocess.Popen("ls ../ | grep -i makefi*", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	if "makefile" in out.lower():
		return "NO ERROR"
	else:
		return out




def main():
	
	comments=""
	testsD = ["test1", "test2", "test3", "test4","test5"]
	commandsD= ["./pa08 -D 1 9 3 | sort >stest1.txt","./pa08 -D 1 1 20 | sort >stest2.txt","./pa08 -D 5 6 7 | sort >stest3.txt","./pa08 -D 7 9 6 | sort >stest4.txt","./pa08 -D 4 8 5 | sort >stest5.txt"]
	linesNumD=[81,171,516,1278,2150]
	
	testsV = ["vtest1","vtest2","vtest3"]
	linesNumV=[255,53,285]
	commandsV= ["./pa08 -VID a a B B 3 3 4 | sort > svtest1.txt","./pa08 -VID a z A Z 1 9 1 | sort > svtest2.txt","./pa08 -VID g h M N 5 6 3 | sort > svtest3.txt"]
	vgrade=[20,10,20]
	
	test_grade=0.0
	no_Makefile_per=0.0
	total_grade=0.0
	late_hours=0
	
	# check if there is a makefile
	IsMakefileFound= cmake()
	if "NO ERROR" not in IsMakefileFound:
		no_Makefile_per=15.0
	
	proc=subprocess.Popen("cp ../main.c ./", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()
	
	proc=subprocess.Popen("cp ../pa08.c ./", stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
	out, err = proc.communicate()

	compile_out= make()
	if "NO ERROR" not in compile_out:
		total_grade=0
		comments="Total Grade:"+repr(total_grade)+"\n=================Compile Error================\n"+compile_out+"\n"
	else:


		proc=subprocess.Popen("touch main.c", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		int_compile_fault=False
		proc=subprocess.Popen("gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DCVID pa08.c main.c Spa08.c -o pa08", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		if out:
			int_compile_fault=True;
			comments=comments+"========createDouble compile error========\n\nYour grade for this function out of 100 is:0\n"+out+"\n"
		else:
			i=0
			while i < len(testsD):
				
				proc=subprocess.Popen(commandsD[i], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
				out, err = proc.communicate()
				if out:
					int_compile_fault=True;
					test_grade=0
					comments=comments+"========createDouble() "+testsD[i]+"========\n\nYour grade for this function out of 20 is:0\n"+out+"\n"
				else:	
					arr,test_grade=grade_file(testsD[i],"s"+testsD[i]+".txt",20,linesNumD[i])
					comments=comments+"========createDouble() "+testsD[i]+"========\n\nYour grade for this function out of 20 is:"+repr(test_grade)+"\n\n"+arr+"\n"
		
				i+=1
				total_grade=total_grade+test_grade




		
		proc=subprocess.Popen("touch main.c", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		vid_compile_fault=False
		proc=subprocess.Popen("gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -DDOUBLE pa08.c main.c Spa08.c -o pa08", stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='/bin/bash')
		out, err = proc.communicate()
		if out:
			vid_compile_fault=True;
			comments=comments+"========createVID compile error========\n\nYour grade for this function out of 50 is:0\n"+out+"\n"
		else:
			i=0
			while i < len(testsV):
				proc=subprocess.Popen(commandsV[i], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,shell=True, executable='/bin/bash')
				out, err = proc.communicate()
				if out:
					vid_compile_fault=True;
					test_grade=0
					comments=comments+"========createVID() "+testsV[i]+"========\n\nYour grade for this function out of "+repr(vgrade[i])+" is:0\n"+out+"\n"
				else:	
					arr,test_grade=grade_file(testsV[i],"s"+testsV[i]+".txt",vgrade[i],linesNumV[i])
					comments=comments+"========createVID() "+testsV[i]+"========\n\nYour grade for this function out of "+repr(vgrade[i]) +" is:"+repr(test_grade)+"\n\n"+arr+"\n"
		
				i+=1
				total_grade=total_grade+test_grade

	


#Late		
	'''late_seconds=0
	late_hours=0
	if submission_time > DEADLINE:
		late_seconds = (submission_time - DEADLINE).total_seconds()
		late_hours = int(late_seconds) / 3600
		comments = comments+ "\n\n****You are {0} hours late***".format(late_hours)

	total_grade = total_grade - 2 * late_hours	'''
	if total_grade < 0:
		total_grade = 0
	if "NO ERROR" not in IsMakefileFound:
		comments=comments+"\n\n**** You have not sumbit a functional make file. Thus, you will lose 15% of your final grade\n\n"
		total_grade = total_grade-(total_grade*0.15)	

	
	comments="Your score out of 100 in this homework (HW08) : "+repr(total_grade)+"\n\n"+comments
		
		
	f=open("./yourGrade.txt","w")
	f.write(comments)
	
	
		

	
	



if __name__ == "__main__":
    main()

















