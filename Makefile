CFLAGS := -std=c99 -g -Og -Werror -Wall -Wpedantic

EXE := lib/main

$(EXE): obj/main.o lib
	$(CC) -Iinc/ $(CFLAGS) -o $(EXE) obj/main.o

obj/main.o: src/main.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o obj/main.o src/main.c

obj:
	mkdir -p obj

lib:
	mkdir -p lib

.PHONY: run
run: $(EXE)
	./$(EXE)

.PHONY: clean
clean:
	rm -rf obj/ lib/

