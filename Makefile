program_name := list
COMPILATOR := g++
compile_flags := -c -O0 -g -std=c++20
link_flags := 
sources :=lists.cpp
objects := $(sources:.cpp=.o)
	
main: $(program_name)
$(program_name): $(objects) 
	$(COMPILATOR) $(objects) -o ./$@
	
.cpp.o:
	$(COMPILATOR) $(compile_flags) $< -o $@

clean:
	rm -rf *.o