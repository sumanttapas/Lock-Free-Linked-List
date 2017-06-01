CXX = g++
CPPFLAGS := -std=c++11 -g
LDFLAGS := -pthread

program_NAME := mylockfree
program_OBJS := LockFreeListFinal.o testProgramIni.o


all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(CXX)  $(CPPFLAGS) $(LDFLAGS) $(program_OBJS) -o $(program_NAME) $(LIBS)
