%: %.cu
	@echo "Compiling $< ..."
	@nvcc -o $@.o $<
	@echo "Running ./$@.o"
	@./$@.o

clean:
	@echo "Cleaning all .o files..."
	@find . -type f -name '*.o' -delete

.PHONY: clean
