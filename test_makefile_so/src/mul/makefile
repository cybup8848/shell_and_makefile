LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar
FLAGS=-g -W -Wall -DDEBUG -fpermissive -fPIC
GCCFLAGS=
LINKFLAG=-shared
LIBS=
HEADER=-I./
BIN_PATH=../../bin/
OBJECT=mul.o
TARGET=libmul.so
$(TARGET):$(OBJECT)
	$(LINK) $(FLAG) $(LINKFLAG) -o $@ $^ $(LIBS)
.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -o $@ $<
.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -o $@ $<
install:$(TARGET)
	$(shell if [ ! -d $(BIN_PATH) ];then mkdir $(BIN_PATH);fi)
	@echo moving $(TARGET)
	@cp $(TARGET) $(BIN_PATH)
clean:
	@rm -rf $(TARGET) *.so *.a
	@rm -rf *.o
