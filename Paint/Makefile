paint.out: main.o canvas.o commands.o command_val.o
	gcc -g -Wall -Werror -o paint.out main.o canvas.o commands.o command_val.o

main.o: main.c  canvas.h structs.h commands.h
	gcc -g -Wall -Werror -c main.c

canvas.o: canvas.c canvas.h structs.h commands.h
	gcc -g -Wall -Werror -c canvas.c

commands.o: commands.c structs.h canvas.h commands.h command_val.h
	gcc -g -Wall -Werror -c commands.c

command_val.o: command_val.c structs.h command_val.h
	gcc -g -Wall -Werror -c command_val.c
clean:
	rm -fr *.o *.out