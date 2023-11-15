LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar

GCCFLAGS=
FLAGS=-g -DDEBUG -fpermissive -fPIC -W -Wall
LINKFLAGS=

HEADER=-I./tradition/
HEADER+=-I./bfprt/
LIBS_PATH=-L./
LIBS_NAME=-ltradition -lbfprt

OBJECT=main.o
TARGET=main

SUB_DIRS =./bfprt/ 
SUB_DIRS +=./tradition/

output_file=~/.bashrc
pwd=$(shell pwd)

define make_sub_dir
@for i in $(SUB_DIRS);do \
	cd $$i; \
	make $1; \
	cd -; \
done;
endef

install:$(OBJECT)
	$(call make_sub_dir,install)
	$(shell if ! test -f $(output_file);then touch $(output_file);fi)
	@echo "export LD_LIBRARY_PATH=LD_LIBRARY_PATH:$(pwd)" >> $(output_file) && . $(output_file)
	$(LINK) $(LINKFLAGS) $(FLAGS) $(LIBS_PATH) -o $(TARGET) $^ $(LIBS_NAME)
.cpp.o:
	$(GCC) $(HEADER) $(FLAGS) $(GCCFLAGS) -c -o $@ $<
.c.o:
	$(GC) $(HEADER) $(FLAGS) -c -o $@ $<
clean:
	$(shell sed -i '$$d' $(output_file) && . $(output_file))
	$(call make_sub_dir,clean)
	@rm -rf *.o *.so *.a
