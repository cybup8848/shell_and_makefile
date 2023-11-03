#########################################################################
# File Name: gen.sh
# Author: cheng yingbin
# mail: 703477993@qq.com
# Created Time: Thu Nov  2 16:33:57 2023
#########################################################################
#!/bin/bash
ARGC=$# #获取命令行个数
ARGV=$@ #获取命令行参数
gen_dir(){
	if [ ! -d "$1" ];then
		mkdir $1
	fi
	cd $1
}

gen_header(){
	file_name="$1.h"
	touch $file_name
	echo "#ifndef __fun_$1__" > $file_name
	echo "#define __fun_$1__" >> $file_name
	echo "$2 $1($2,$2);" >> $file_name
	echo "#endif" >> $file_name
}

gen_source(){
	file_name="$1.cpp"
	touch $file_name
	echo -e "#include\"$1.h\"" > $file_name
	echo -e "$2 $1($2 a,$2 b){" >> $file_name
	op=+
	if [ "$1" == "add" ];then
		op=+
	elif [ "$1" == "sub" ];then
		op=-
	elif [ "$1" == "mul" ];then
		op=*
	else
		op=/
	fi
	echo -e "\t return a $op b;" >> $file_name
	echo -e "}" >> $file_name
}

gen_file(){
	gen_dir $1
	gen_header $1 $2
	gen_source $1 $2
	cd ..
}

gen_file add int
gen_file sub int
gen_file mul int
gen_file sdiv int
