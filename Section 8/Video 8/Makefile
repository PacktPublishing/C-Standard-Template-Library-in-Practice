CXX = g++-8
CXXFLAGS = -O3 -Wall -Wextra --std=c++17
LDFLAGS = -pthread -lstdc++fs
OBJS = match.o
EXE = match

$(EXE) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@ 

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm *.o
	rm $(EXE)


