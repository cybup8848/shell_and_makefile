#生成可执行文件

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/cyb/make_file_learn/test_makefile_so/bin
#export的意思是设置一个环境变量，$LD_LIBRARY_PATH的意思是，获取环境变量LD_LIBRARY_PATH当前的值
#:/home/veroll/Linux/lesson1.6/ibrary/lib的意思是，在冒号后写上要新加入环境变量的值，即动态库的绝对路径是
#  /home/veroll/Linux/lesson1.6/library/lib
#刚才配置环境变量时，本质上是在刚才使用的终端中配置的环境变量(临时的环境变量)，一旦关闭刚才的终端，再新启动一个终端，再次运行main时，就又会报错。

#因此最好配置一个永久的环境变量。配置永久的环境变量又有两种方法，一种是用户级别，另一种是系统级别。
#用户级别：配置永久环境变量，输入命令cd或命令cd /home/veroll/,进入用户目录(veroll)下
#	输入vim ./.bashrc ，编辑，末尾插入export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/veroll/Linux/lesson1.6/library/lib，保存
#接着输入指令：source ./.bashrc，用法：source filename，使修改生效，通知当前shell读入路径为filename的文件并依次执行
#文件中的所有语句，该命令通常用.替代，如source ./.bashrc与. ./.bashrc等价

#系统级别：配置永久环境变量
#在任意目录下，输入如下命令：sudo vim /ect/profile，然后输入用户密码
#然后编辑，在最后添加export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/veroll/Linux/lesson1.6/library/lib
#保存退出，source /etc/profile，使修改生效


LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc

FLAGS=-g -W -Wall -DDEBUG -fpermissive -fPIC
GCCFLAGS=
LINKFLAGS=

HEADER=-I./
HEADER+=-I./add
HEADER+=-I./sub
HEADER+=-I./mul
HEADER+=-I./sdiv

LIBS=
LIBS+=-L../bin -ladd
LIBS+=-lsub
LIBS+=-lmul
LIBS+=-lsdiv

BIN_PATH=../bin

TARGET=main
OBJECT=main.o

$(TARGET):$(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -o $@ $<

.c.o:
	$(GC) -c $(HADER) $(FALGS) -o $@ $<

install:$(TARGET)
	@if [ ! -d $(BIN_PATH) ];then \
		mkdir $(BIN_PATH); \
	fi
	@echo moving $(TARGET)
	@cp $(TARGET) $(BIN_PATH)
	
clean:
	@rm -rf $(TARGET) *.o *.so *.a


