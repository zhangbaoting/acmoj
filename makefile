
main:main.cpp config.h
	g++  main.cpp -o main -I/usr/include/mysql -lmysqlclient -L/usr/lib/mysql
