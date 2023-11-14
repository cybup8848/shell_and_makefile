LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar

LINKFLAG=-shared
FLAGS=-g -DDEBUG -W -Wall -fpermissive -fPIC
GCCFLAGS=

HEADER=-I./
LIBS_NAME=
LIBS_PATH=

OBJECT=tradition.o
TARGET=libtradition.so
BIN_PATH=../

$(TARGET):$(OBJECT)
	$(LINK) $(LINKFLAG) $(FLAGS) $(LIBS_PATH) -o $@ $^ $(LIBS_NAME)
.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -o $@ $^
.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -o $@ $^
install:$(TARGET)
	@cp $(TARGET) $(BIN_PATH)
clean:
	@rm -rf *.o *.so
