main:
	gcc src/*.c src/utils/*.c tests/*.c tests/utils/*.c -Wall -Wextra -pedantic -std=c99 -o main

run:
	./main

clean:
	rm main

all:
	gcc src/*.c src/utils/*.c tests/*.c tests/utils/*.c -Wall -o main
	./main
	rm main
