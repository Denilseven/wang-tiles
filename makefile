COMPILER = cc
SOURCES = main.c
OUTPUT = out.out
FLAGS = 

default: build

build:
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(FLAGS)

run: build
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)

