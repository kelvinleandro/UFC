# Custom rule: "make <filename>" compiles AND runs the program
%: %.c
	@echo "Compiling $<..."
	@gcc -o $@.o $<
	@echo "Running ./$@.o"
	@./$@.o

# Recursive clean (removes ALL .o files in current + subdirectories)
clean:
	@echo "Cleaning all .o files..."
	@find . -type f -name '*.o' -delete

.PHONY: clean