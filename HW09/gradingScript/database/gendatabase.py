import csv
import pickle
import random


def read_name(filename):
	names = []
	with open(filename, 'r') as csvfile:
		reader = csv.reader(csvfile)
		for row in reader:
			names.append(row[0])
	random.shuffle(names) # shuffle name
	return names # return first hundred names

def main():
	names = read_name("name.txt")
	majors = ["ECE", "CS", "ME", "AA", "ABE", "BME", "CHE", "IE"]
	year = ["Freshman", "Sophomore", "Junior", "Senior"]
	enronment = ["Yes", "No"]
	age = [i for i in range(10,30)]
	for j in range(100,101):
		stu_number = j*10
		filename = "testdb"+"Large" #+".txt"
		f = open(filename, "w")
		for i in xrange(0, stu_number):
			student = "{0},{1},{2},{3},{4},{5}".format(i+1, names[random.randint(0, len(names)-1)], majors[random.randint(0, 7)],
							year[random.randint(0, 3)], enronment[random.randint(0, 1)],
							age[random.randint(0, len(age)-1)])
			student+="\n"
			f.write(student)
		f.close()
	
if __name__ == '__main__':
	main()
