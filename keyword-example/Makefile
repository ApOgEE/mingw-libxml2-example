# Author: M. Fauzilkamil Zainuddin <apogee@apogeek.com>
CC=gcc

all: keyword

keyword: keyword.c
	# compiling keyword sample
	$(CC) -o $@ $< `xml2-config --cflags --libs`

clean:
	# removing keyword.exe in MinGW
	rm -rf keyword.exe
	# thinking about keyword binary in Linux (untested)
	rm -rf keyword