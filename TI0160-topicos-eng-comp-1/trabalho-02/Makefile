CXX = g++

CXXFLAGS = -std=c++14 -Wall -Wextra -g

TARGET = sistema_academico.o

SOURCES = main.cpp Escola.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)

.PHONY: all clean run