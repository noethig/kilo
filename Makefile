all: kilo

kilo: kilo.c
	$(CC) -o kiloCrypt kiloCrypt.c -Wall -W -pedantic -std=c99

clean:
	rm kilo
