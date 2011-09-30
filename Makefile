APP ?= db-test
OBJS = mysqldb.o main.o

LIBS = -Lmysql-connector/lib/ -lmysqlclient
INCLUDE = -Imysql-connector/include/
CC = g++
CFLAGS = -Wall -pedantic -ggdb -O2 -Wno-long-long


all: $(APP)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -c -o $@ $< 

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@ $(OBJS)

clear:
	rm -f $(OBJS) $(APP)
