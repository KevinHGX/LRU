#Macros = Objs/Directory
TARGET = out_lru
OBJS = Main.o LRU.o
CXX = g++
#-g Depuracion
#-Wall warning 
CXXFLAGS = -g -Wall
#-------------------------------
#Target  : Dependencias 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

#-------------------------------
#----------------- op 1 ----------------------------------
#Regla de "make" implicita compilar un fichero
#de fuente C++ para obtener su objeto
#Main.o: Main.cpp Board.h
#	$(CC) -c Main.cpp   << puedo agregarlo o no, igual funcionara 
#----------------- op 2 ----------------------------------
#Main.o: Main.cpp Board.h
#Board.o: Board.cpp Board.h
#----------------- op 3 ----------------------------------
$(OBJS) = LRU.h

#Objetivo falsos
.PHONY: clean 

clean:
	rm *.o $(TARGET)