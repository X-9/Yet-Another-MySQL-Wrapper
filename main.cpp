#include "mysqldb.h"

#include <iostream>


int main(int argc, char *argv[])
{
	MySQLDb mysqldb("127.0.0.1", "user", "password", "db_name");
	mysqldb.create_table("my_test");

	return 0;
}

