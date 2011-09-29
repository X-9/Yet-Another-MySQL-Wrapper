APP ?= db-test
OBJS = mysqldb.o main.o

CONFIG = /opt/local/bin/mysql_config5
LIBS = $(shell $(CONFIG) --libmysqld-libs)
INCLUDE = #$(shell $(CONFIG) --include)
CC = g++
CFLAGS = -Wall -pedantic -ggdb -O2 -Wno-long-long $(shell $(CONFIG) --cflags)


all: $(APP)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -c -o $@ $< 

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@ $(OBJS)

clear:
	rm -f $(OBJS) $(APP)
