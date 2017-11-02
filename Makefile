# universal Makefile V 0.3
# Piotr Kolecki

CXX = g++
CXXFLAGS = -g -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = $(wildcard *.h)

DAT=`date +'_%H_%m_%s'`
DIR=`basename \`pwd\``

all : output.exe

output.exe : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : all release backup clear run
.SILENT : release

release : all
	mkdir ./release/
	cp output.exe ./release/
	cp $(SRC) ./release/
	cp $(HDR) ./release/
	cp Makefile ./release/
	rm output.exe
	rm *.o
	tar -czf $(DIR).tar.gz ./release/
backup : all
	mkdir ./backup$(DAT)/
	cp $(SRC) ./backup$(DAT)/
	cp $(HDR) ./backup$(DAT)/
	cp Makefile ./backup$(DAT)/
clear : 
	rm -f output.exe
	rm -f *.o
run : output.exe
	./output.exe
