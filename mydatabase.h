#ifndef __MY_DATABASE__H
#define __MY_DATABASE__H

#include <string>

#include "sqlite-amalgamation-3240000/sqlite3.h"

class MyDatabase
{
public:
	MyDatabase(const std::string& _fileName);
private:
	sqlite3* m_db;
};

#endif