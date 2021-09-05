CC = clang
RM = rm -f
OUTPUT = clox

default: build

build:
	$(CC) *.c -o $(OUTPUT)

clean:
	$(RM) $(OUTPUT)
