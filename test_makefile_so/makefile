#先编译库文件
SUBDIRS=./src/add
SUBDIRS+=./src/sub
SUBDIRS+=./src/mul
SUBDIRS+=./src/sdiv
SUBDIRS+=./src#最后编译程序

BIN_PATH==./bin

define make_subdir
@for i in $(SUBDIRS);do \
	cd $$i; \
	make $1; \
	cd -; \
done;
endef

#默认的目标为编译所有子目录
ALL:
	$(shell if [ ! -d $(BIN_PATH) ];then mkdir $(BIN_PATH);fi;)
	$(call make_subdir)

#清空所有子目录
clean:
	$(shell if test -d $(BIN_PATH);then rm -rf $(BIN_PATH);fi;)
	$(call make_subdir,clean)

#把子目录里生成的程序或so都拷到$(BIN_PATH)目录下
install:
	$(shell if ! test -d $(BIN_PATH);then mkdir $(BIN_PATH);fi;)
	$(call make_subdir,install)












