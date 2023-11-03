LINK=@echo linking $@ && g++
GCC=@echo compling $@ && g++
GC=@echo compling $@ && gcc
AR=@echo generating static library $@ && ar
FLAGS=-g -W -Wall -DDEBUG -fpermissive -fPIC
GCCFLAGS=
LINKFLAG=
LIBS=
HEADER=-I./
BIN_PATH=../../bin/
OBJECT=sub.o
TARGET=libsub.a
$(TARGET):$(OBJECT)
	$(AR) -c -r $@ $^
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
