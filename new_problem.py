#-*- coding:utf-8 -*-

import os
import shutil
import sys

make_str='''CC=c++
target=%s
all: a.out
a.out: ${target}.cpp
	${CC} -std=c++11 -o $@ $^

clean:
	rm a.out
'''

cpp_str='''
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{

	return 0;
}
'''

def main():
	argv = sys.argv
	name = "_".join(argv[1:])
	if not os.path.exists(name):
		os.makedirs(name)
		print "makedirs:",name
	f_name = name+"/"+name+".cpp"
	if not os.path.exists(f_name):
		with open(f_name,"w") as f:
			f.write(cpp_str)
		print "create file:%s"%f_name
	f_name = name+"/"+"Makefile"
	if not os.path.exists(f_name):
		with open(f_name,"w") as f:
			f.write(make_str%name)
		print "create file:%s"%f_name



if __name__ == '__main__':
	main()