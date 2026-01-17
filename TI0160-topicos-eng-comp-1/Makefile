CXX     := g++
NVCC    := nvcc
CXXFLAGS := -std=c++14 -Wall -Wextra -g

# Example usage:
#    make cpp <filename>   -> compiles & runs filename.cpp
#    make cuda <filename>  -> compiles & runs filename.cu

TARGET := $(word 2, $(MAKECMDGOALS))

# Disable default filename interpretation
%:
	@:

cpp:
	@if [ -z "$(TARGET)" ]; then \
		echo "Usage: make cpp <filename>"; \
	else \
		echo "Compiling $(TARGET).cpp ..."; \
		$(CXX) $(CXXFLAGS) -o $(TARGET).o $(TARGET).cpp && \
		echo "Running ./$(TARGET).o" && \
		./$(TARGET).o; \
	fi

cuda:
	@if [ -z "$(TARGET)" ]; then \
		echo "Usage: make cuda <filename>"; \
	else \
		echo "Compiling $(TARGET).cu ..."; \
		$(NVCC) -o $(TARGET).o $(TARGET).cu && \
		echo "Running ./$(TARGET).o" && \
		./$(TARGET).o; \
	fi

# Recursive clean (removes ALL .o files in current + subdirectories)
clean:
	@echo "Cleaning all .o files..."
	@find . -type f -name '*.o' -delete

.PHONY: cpp cuda clean