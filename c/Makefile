# Variables:
# $@  : target name
# $?  : prerequisites
# $^  : all prerequisites

SRC_FILES = main.c
OBJ_FILES = main.o set.o

.PHONY: build 

%.o: %.c
		@gcc -c $< -o build/$@

all: $(OBJ_FILES)
	  @echo "Linking object files..."
		gcc build/*.o -o build/napoleon

build: clean all 

clean:
		mkdir -p build
		rm -Rf build/*

run: build
		./build/napoleon
