CXX = g++

CXXFLAGS = -std=c++14 -Wall -Wextra -g

TARGET = sistema_bancario.o

SOURCES = main.cpp Banco.cpp Cliente.cpp Conta.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean