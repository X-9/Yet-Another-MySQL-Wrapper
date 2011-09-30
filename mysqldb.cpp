#include "mysqldb.h"

MySQLDb::MySQLDb(const std::string &host,
                 const std::string &user,
                 const std::string &passwd,
                 const std::string &db)
    : m_host(host)
    , m_user(user)
    , m_passwd(passwd)
    , m_db(db)
{
    m_connect = NULL;
    m_result = NULL;
}

MySQLDb::~MySQLDb()
{
    if (m_connect)
    {
        mysql_close(m_connect);
    }
}

bool MySQLDb::create_table(const std::string &name)
{
    if (!connect_db())
    {
        return false;
    }

    const std::string &query = 
        "CREATE TABLE `result` ("
        "`id` INT NOT NULL AUTO_INCREMENT,"
        "`x` DOUBLE NOT NULL,"
        "`y` DOUBLE NOT NULL,"
        "`z` DOUBLE NOT NULL,"
        "PRIMARY KEY (`id`));";

    // Nonzero if an error occurred.
    if (mysql_query(m_connect, query.c_str())
        && mysql_commit(m_connect))
    {
        std::cerr << "Failed to create a table : " 
                  << mysql_error(m_connect) 
                  << std::endl;
        return false;
    }

    return true;
}

bool MySQLDb::connect_db()
{
    if (m_connect)
    {
        return true;
    }

    m_connect = mysql_init(NULL);

    if (NULL == mysql_real_connect(m_connect,
                                   m_host.c_str(),
                                   m_user.c_str(),
                                   m_passwd.c_str(),
                                   m_db.c_str(),
                                   0,
                                   NULL,
                                   0))
    {
        std::cerr << "Failed to connect : " 
                  << mysql_error(m_connect)
                  << std::endl;
        return false;
    }

    return true;
}

