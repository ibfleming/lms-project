# Makefile

TARGET = lms
CC = g++
CFLAGS = -Wall -g
SRCS = library.cpp user.cpp util.cpp main.cpp
HDRS = library.hpp user.hpp util.hpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET).out

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ $(TARGET).out $(OBJS) | clear

tar: $(HDRS) $(SRCS) Makefile
	tar -cvf $(TARGET).tar $(HDRS) $(SRCS) Makefile | clear