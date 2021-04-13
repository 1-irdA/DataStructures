FROM gcc:latest

ADD . /app/

WORKDIR /app/

RUN gcc src/*.c tests/*.c tests/utils/*.c -Wall -Wextra -pedantic -std=c99 -o main

CMD ["./main"]
