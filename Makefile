a.out : event.c calendar.c main.c
        cc event.o calendar.o main.o -o a.out
event.o : event.c event.h color.h
        cc -c event.c
calendar.o : calendar.c calendar.h
        cc -c calendar.c
main.o : main.c event.h calendar.h
        cc -c main.c