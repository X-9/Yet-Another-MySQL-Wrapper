#ifndef _MYSQLDB_INCLUDED_
#define _MYSQLDB_INCLUDED_

#include <iostream>

extern "C"
{
#include <mysql.h>
}

class MySQLDb
{
public:
	MySQLDb(const std::string &host,
			const std::string &user,
			const std::string &passwd,
			const std::string &db);
	virtual ~MySQLDb();

    // Returns true if table was succesfully created, false if an error occured.
	bool create_table(const std::string &name);

private:
    // Returns true if connection was succesfully created or already exists.
	bool connect_db();

	std::string m_host;
	std::string m_user;
	std::string m_passwd;
	std::string m_db;

	MYSQL *m_connect;
	MYSQL_RES *m_result;
};

#endif // _MYSQLDB_INCLUDED_


