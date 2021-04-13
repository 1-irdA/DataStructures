FROM gcc:latest

ADD . /app/

WORKDIR /app/

RUN gcc src/*.c src/utils/*.c tests/utils/*.c tests/main.c -Wall -Wextra -pedantic -std=c99 -g -o main

CMD ["./main"]
