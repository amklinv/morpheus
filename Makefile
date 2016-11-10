CFLAGS = -g -O0 --coverage -I.
LFLAGS = --coverage 

# Main target
all: Morpheus_Matrix_Tests.exe Morpheus_Vector_addScaleTest.exe Morpheus_Vector_normTest.exe

# Rules for the .o files
Morpheus_Vector.o: Morpheus_Vector.cpp Morpheus_Vector.h
	$(CXX) $(CFLAGS) -c Morpheus_Vector.cpp

Morpheus_Matrix.o: Morpheus_Matrix.cpp Morpheus_Matrix.h
	$(CXX) $(CFLAGS) -c Morpheus_Matrix.cpp

Morpheus_Matrix_Tests.o: test/Morpheus_Matrix_Tests.cpp
	$(CXX) $(CFLAGS) -c test/Morpheus_Matrix_Tests.cpp

Morpheus_Vector_addScaleTest.o: test/Morpheus_Vector_addScaleTest.cpp
	$(CXX) $(CFLAGS) -c test/Morpheus_Vector_addScaleTest.cpp

Morpheus_Vector_normTest.o: test/Morpheus_Vector_normTest.cpp
	$(CXX) $(CFLAGS) -c test/Morpheus_Vector_normTest.cpp

# Rules for the executables
Morpheus_Matrix_Tests.exe: Morpheus_Matrix_Tests.o Morpheus_Matrix.o Morpheus_Vector.o
	$(CXX) $(LFLAGS) -o Morpheus_Matrix_Tests.exe Morpheus_Matrix_Tests.o Morpheus_Matrix.o Morpheus_Vector.o

Morpheus_Vector_addScaleTest.exe: Morpheus_Vector_addScaleTest.o Morpheus_Vector.o
	$(CXX) $(LFLAGS) -o Morpheus_Vector_addScaleTest.exe Morpheus_Vector_addScaleTest.o Morpheus_Vector.o

Morpheus_Vector_normTest.exe: Morpheus_Vector_normTest.o Morpheus_Vector.o
	$(CXX) $(LFLAGS) -o Morpheus_Vector_normTest.exe Morpheus_Vector_normTest.o Morpheus_Vector.o

clean:
	rm -f *.o *.exe *.gcda *.gcno *.gcov
