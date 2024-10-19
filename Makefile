
# Compiler and compiler flags
CC = g++
CFLAGS = -Wall -Werror -std=c++11

# Target executable
TARGET = loadbalancer

# Source files
SRCS = main.cpp Request.cpp RequestQueue.cpp WebServer.cpp LoadBalancer.cpp RandomGenerator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build the target executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the target executable
clean:
	rm -f $(TARGET) $(OBJS)
