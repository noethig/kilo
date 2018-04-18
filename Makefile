all: kiloCrypt

kiloCrypt: kiloCrypt.c
	$(CC) -o kilocrypt kiloCrypt.c -Wall -W -pedantic -std=c99

clean:
	rm kilocrypt
