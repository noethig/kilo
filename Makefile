all: kiloCrypt

kiloCrypt: kiloCrypt.c
	$(CC) -o kiloCrypt kiloCrypt.c -Wall -W -pedantic -std=c99

clean:
	rm kiloCrypt
