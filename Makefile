# #  kkorenn1@gmail.com 209271535

# CXX=clang++
# CXXFLAGS=-std=c++11
# SOURCES=Graph.cpp Algorithms.cpp Demo.cpp
# OBJECTS=$(SOURCES:.cpp=.o)

# run: demo
# 	./demo

# demo: $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	rm -f *.o demo
#!make -f

CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: test
	./$^

demo: Demo.o Algorithms.o Graph.o
	$(CXX) $(CXXFLAGS) $^ -o demo

test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-,clang-analyzer-,cppcoreguidelines-,performance-,portability-,readability-,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test