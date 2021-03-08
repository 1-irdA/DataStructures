main:
	gcc src/*.c src/utils/*.c tests/utils/*.c tests/main.c -Wall -Wextra -pedantic -std=c99 -g -o main

run:
	./main

clean:
	rm main

all:
	rm main
	gcc src/*.c src/utils/*.c tests/utils/*.c tests/main.c -Wall -g -o main
	./main