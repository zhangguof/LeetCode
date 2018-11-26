#-*- coding:utf-8 -*-

import os
import shutil
import sys

make_str='''CC=c++
target=%s
all: ${target}
$target: ${target}.cpp
	$CC -o $@ $^

clean:
	rm ${target}
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
			pass
		print "create file:%s"%f_name
	f_name = name+"/"+"Makefile"
	if not os.path.exists(f_name):
		with open(f_name,"w") as f:
			f.write(make_str%name)
		print "create file:%s"%f_name



if __name__ == '__main__':
	main()