# Author: M. Fauzilkamil Zainuddin <apogee@apogeek.com>
CC=gcc

all: webrequest

webrequest: webrequest.c
	# compiling webrequest sample
	$(CC) -o $@ $< `xml2-config --cflags --libs`

clean:
	# removing webrequest.exe in MinGW
	rm -rf webrequest.exe
	# thinking about webrequest binary in Linux (untested)
	rm -rf webrequest
	# removing xml files
	rm -rf *.xml