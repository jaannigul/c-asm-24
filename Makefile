# Define compiler and flags
CC := gcc
ASM := nasm
CFLAGS := -m32 -std=c11 -g -Og -Werror -Wall -Wpedantic -DDEBUG -no-pie
ASMFLAGS := -felf32
# Executable names
EXE := lib/main
BFI_EXE := bfi
HELLO_EXE := hello
COLLAZ_TEST_EXE := collaz_test

# Default target to build all executables
all: $(BFI_EXE) $(EXE) $(HELLO_EXE) $(COLLAZ_TEST_EXE)
# ----------------------------------------------------------------------
# Build the collaz_test executable
$(COLLAZ_TEST_EXE): obj/collaz.o obj/collaz_test.o
	$(CC) -m32 -o $(COLLAZ_TEST_EXE) obj/collaz.o obj/collaz_test.o

# Assemble collaz.asm
obj/collaz.o: src/collaz.asm obj
	$(ASM) $(ASMFLAGS) -o obj/collaz.o src/collaz.asm

# Compile collaz_test.c
obj/collaz_test.o: src/collaz_test.c obj
	$(CC) -c -m32 $(CFLAGS) -o obj/collaz_test.o src/collaz_test.c
# ----------------------------------------------------------------------
# Build the hello executable
$(HELLO_EXE): obj/hello.o obj/mem.o
	$(CC) -m32 -o $(HELLO_EXE) obj/hello.o obj/mem.o

# Assemble hello.asm
obj/hello.o: src/hello.asm | obj
	$(ASM) $(ASMFLAGS) -o obj/hello.o src/hello.asm
# ----------------------------------------------------------------------

# Build the bfi executable
$(BFI_EXE): obj/bfi.o obj/stack.o obj/mem.o obj/instructions.o lib
	$(CC) $(CFLAGS) -o $(BFI_EXE) obj/bfi.o obj/mem.o obj/stack.o obj/instructions.o

# Build the main executable
$(EXE): obj/main.o obj/stack.o obj/mem.o lib
	$(CC) $(CFLAGS) -o $(EXE) obj/main.o obj/stack.o obj/mem.o

# Compile bfi.c
obj/bfi.o: src/bfi.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/bfi.o src/bfi.c

# Compile main.c
obj/main.o: src/main.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/main.o src/main.c

# Compile stack.c
obj/stack.o: src/stack.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/stack.o src/stack.c

# Compile mem.c
obj/mem.o: src/mem.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/mem.o src/mem.c

# Compile instructions.c
obj/instructions.o: src/instructions.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/instructions.o src/instructions.c

# Create the 'obj' directory if it doesn't exist
obj:
	mkdir -p obj

# Create the 'lib' directory if it doesn't exist
lib:
	mkdir -p lib

# Run the main program
.PHONY: run
run: $(EXE)
	./$(EXE)

# Run the bfi program
.PHONY: run_bfi
run_bfi: $(BFI_EXE)
	./$(BFI_EXE)
# ----------------------------------------------------------------------
.PHONY: run_hello
run_hello: $(HELLO_EXE)
	./$(HELLO_EXE)

# Run the collaz_test program
.PHONY: run_collaz_test
run_collaz_test: $(COLLAZ_TEST_EXE)
	./$(COLLAZ_TEST_EXE)
# ----------------------------------------------------------------------
# Clean up all generated files
.PHONY: clean
clean:
	rm -rf obj/ lib/ $(EXE) $(BFI_EXE) $(HELLO_EXE) $(COLLAZ_TEST_EXE)
