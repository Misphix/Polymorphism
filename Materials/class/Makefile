CC = g++
CFLAGS = -Wall -O2
DEL = del /f

main: main.cpp comic.o novel.o magazine.o book.o
	 $(CC) -o $@ $^

comic.o: comic.h comic.cpp book.o
	 $(CC) -o $@ -c comic.cpp

novel.o: novel.h novel.cpp book.o
	 $(CC) -o $@ -c novel.cpp

magazine.o: magazine.h magazine.cpp book.o
	 $(CC) -o $@ -c magazine.cpp

book.o: book.h book.cpp
	 $(CC) -o $@ -c book.cpp

clean:
	 $(DEL) *.o main.exe