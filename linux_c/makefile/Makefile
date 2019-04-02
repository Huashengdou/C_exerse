add:main.o add_num.o
	gcc -o add add_num.o main.o
main.o:main.c
	gcc -c main.c
add_num.o:add_num.c
	gcc -c add_num.c
clean:
	rm main.o add_num.o add
