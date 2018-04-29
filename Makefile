all: kiloCrypt

kiloCrypt: kiloCrypt.c
	$(CC) -o kilocrypt kiloCrypt.c -Wall -W -pedantic -std=c99

clean:
	rm kilocrypt

encryptor: encryptor.c hashmap.o hashmap.h
	$(CC) -o encryptor encryptor.c hashmap.o -Wall -W -pedantic -std=c99
