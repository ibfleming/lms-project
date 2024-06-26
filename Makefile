# Makefile

TARGET = lms
CC = g++
CFLAGS = -Wall -g
#-Wextra -Werror -pedantic
SRCS = library.cpp user.cpp book.cpp util.cpp gui.cpp main.cpp
HDRS = library.hpp user.hpp book.hpp util.hpp gui.hpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ $(TARGET) $(OBJS) | clear

tar: $(HDRS) $(SRCS) Makefile
	tar -cvf $(TARGET).tar $(HDRS) $(SRCS) Makefile | clear