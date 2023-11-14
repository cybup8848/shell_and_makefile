#########################################################################
# File Name: gen_makefile.sh
# Author: cheng yingbin
# mail: 703477993@qq.com
# Created Time: Thu Nov  2 22:54:52 2023
#########################################################################
#!/bin/bash

#获取参数个数、参数列表
ARGC=$#
ARGV=$@
isSO=false
file=cyb
for arg in $ARGV;do
	case $arg in
	-static)
		isSO=false
	;;
	-shared)
		isSO=true
	;;
	*)
		file=$arg
	;;
	esac
done
file_name=./$file/makefile
if [ ! -f file_name ];then
	touch ./$file/makefile
fi

link="LINK=@echo linking \$@ && g++"
gcc="GCC=@echo compling \$@ && g++"
gc="GC=@echo compling \$@ && gcc"
ar="AR=@echo generating static library \$@ && ar"

flags="FLAGS=-g -W -Wall -DDEBUG -fpermissive -fPIC"
gccflags="GCCFLAGS="
linkflag="LINKFLAG="
if $isSO;then
	linkflag="LINKFLAG=-shared"
fi
libs="LIBS="
header="HEADER=-I./"
TARGET_SO="TARGET=lib$file.so"
TARGET_A="TARGET=lib$file.a"
OBJECT="OBJECT=$file.o"
bin_path="BIN_PATH=../../bin/"

so_item="\$(TARGET):\$(OBJECT)\n\t\$(LINK) \$(FLAG) \$(LINKFLAG) -o \$@ \$^ \$(LIBS)"
a_item="\$(TARGET):\$(OBJECT)\n\t\$(AR) -c -r \$@ \$^"

gcc_item=".cpp.o:\n\t\$(GCC) -c \$(HEADER) \$(FLAGS) \$(GCCFLAGS) -o \$@ \$<"
gc_item=".c.o:\n\t\$(GC) -c \$(HEADER) \$(FLAGS) -o \$@ \$<"

install_item="install:\$(TARGET)\n\t\$(shell if [ ! -d \$(BIN_PATH) ];then mkdir \$(BIN_PATH);fi)\n\t@echo moving \$(TARGET)\n\t@cp \$(TARGET) \$(BIN_PATH)"

clean_item="clean:\n\t@rm -rf \$(TARGET) *.so *.a"

echo -e $link > $file_name
echo -e $gcc >> $file_name
echo -e $gc >> $file_name
echo -e $ar >> $file_name
echo -e $flags >> $file_name
echo -e $gccflags >> $file_name
echo -e $linkflag >> $file_name
echo -e $libs >> $file_name
echo -e $header >> $file_name

echo -e $bin_path >> $file_name
echo -e $OBJECT >> $file_name
if $isSO;then
	echo -e $TARGET_SO >> $file_name
	echo -e $so_item >> $file_name
else
	echo -e $TARGET_A >> $file_name
	echo -e $a_item >> $file_name
fi
echo -e $gcc_item >> $file_name
echo -e $gc_item >> $file_name
echo -e $install_item >> $file_name
echo -e $clean_item >> $file_name
echo -e "\t@rm -rf *.o" >> $file_name
