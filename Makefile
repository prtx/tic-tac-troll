play:
	./tictactroll

install:
	sudo apt install build-essential -y

build:
	gcc -o tictactroll tictactroll.c