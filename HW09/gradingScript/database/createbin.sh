#!/bin/bash
for filelist in `find . -name "testdb*"`;
	do
	../filewrite ${filelist} ${filelist}.bin 
	done
