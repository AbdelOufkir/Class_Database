CXXFLAGS := -std=c++11
OBJS := driver.o Student.o Instructor.o Course.o

# executable files to create and its dependencies
course.exe : $(OBJS)
	g++ $(CXXFLAGS) -o course $(OBJS)

# file dependencies
Student.o : Student.h
	g++ $(CXXFLAGS) -c Student.cpp
Instructor.o : Instructor.h
	g++ $(CXXFLAGS) -c Instructor.cpp
Course.o : Course.h Student.h Instructor.h
	g++ $(CXXFLAGS) -c Course.cpp
driver.o : Course.h
	g++ $(CXXFLAGS) -c driver.cpp

# files to remove
clean:
	del $(OBJS)
	del course.exe
