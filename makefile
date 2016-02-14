all:main
main:information_manage.o main.o
	gcc information_manage.o main.o -o main
information_manage.o:information_manage.c information_manage.h
	gcc -c information_manage.c
main.o: main.c information_manage.h
	gcc -c main.c