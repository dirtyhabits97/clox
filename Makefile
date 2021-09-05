CC = clang
RM = rm -f
OUTPUT = clox

default: build

build:
	$(CC) Sources/*.c -o $(OUTPUT)

clean:
	$(RM) $(OUTPUT)
