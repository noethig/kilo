all: kiloCrypt

kiloCrypt: kiloCrypt.c
	$(CC) -o kilocrypt kiloCrypt.c -Wall -W -pedantic -std=c99

clean:
	rm kilocrypt

encryptor: encryptor.c
	$(CC) -o encryptor encryptor.c -Wall -W -pedantic -std=c99
