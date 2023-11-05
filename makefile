LINK=@echo linkging $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar cr
FLAGS=-g -DDEBUG -W -Wall -fPIC -fpermissive
GCCFLAGS=
DEFINES=
LIBS=
LINKFLAGS=

HEADER=-I./

TARGET=main
OBJECT := main.o \
		  test_class.o

BIN_PATH=./hello

$(TARGET):$(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(GCC) -c $(FLAGS) $(GCCFLAGS) $(HEADER) -o $@ $<

.c.o:
	$(GC) -c $(FLAGS) $(HEADER) -o $@ $<

install:$(TARGET)
	@echo moving $<
	cp -rf $(TARGET) $(BIN_PATH)

clean:
	rm -rf $(TARGET) *.o *.so *.a







