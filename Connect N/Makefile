connectn.out: main.o play_game.o board.o val.o
	gcc -g -Wall -Werror -o connectn.out main.o play_game.o board.o val.o
main.o: main.c play_game.h val.h board.h
	gcc -g -Wall -Werror -c main.c
play_game.o: play_game.c play_game.h board.h val.h
	gcc -g -Wall -Werror -c play_game.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
val.o: val.c val.h
	gcc -g -Wall -Werror -c val.c
clean:
	rm -fr *.o *.out