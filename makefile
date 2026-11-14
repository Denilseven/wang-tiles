COMPILER = cc
SOURCES = main.c
OUTPUT = out.out
FLAGS = -Iinclude -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

default: build

build:
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(FLAGS)

run: build
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)

