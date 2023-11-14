LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar

FLAGS=-g
FLAGS+=-DDEBUG
FLAGS+=-fPIC -fpermissive
FLAGS+=-W -Wall
GCCFLAGS=
LINKFLAGS=

HEADER=-I./
LIBS_PATH=
LIBS_NAME=

BIN_PATH=../
OBJECT=bfprt.o
TARGET=libbfprt.a

$(TARGET):$(OBJECT)
	$(AR) -c -r $@ $^
.cpp.o:
	$(GCC) $(HEADER) $(GCCFLAGS) $(FLAGS) -c -o $@ $<
.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -o $@ $<
install:$(TARGET)
	@cp $(TARGET) $(BIN_PATH)
clean:
	@rm -rf *.o *.a





