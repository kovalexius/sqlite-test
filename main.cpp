#include <iostream>
#include "sqlite-amalgamation-3240000/sqlite3.h"

const char* CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS foo(a,b,c);"; 
const char* SQL_INSERT = "INSERT INTO FOO VALUES(1, 2, 3); INSERT INTO FOO SELECT * FROM FOO; ";

void writeToBase(sqlite3 *_db)
{
	char *err = 0;
	// ��������� SQL
	if (sqlite3_exec(_db, SQL_INSERT, 0, 0, &err))
	{
		std::cerr << "������ SQL: " << err << std::endl;
		sqlite3_free(err);
	}
	// ��������� ����������
	sqlite3_close(_db);
}

const char* SQL_SELECT = "SELECT * FROM FOO;";

int select_callback(void*, int _numColumns, char** _values, char** _columns)
{
	std::cout << "Number of columns:" << _numColumns << std::endl;

	std::cout << "values: ";
	for (auto i = 0; i < _numColumns; i++)
	{
		std::cout << _values[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "columns: ";
	for (auto i = 0; i < _numColumns; i++)
	{
		std::cout << _columns[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

void readFromBase()
{
	sqlite3 *db = 0; // ����� ������� ���������� � ��
	char *err = 0;

	// ��������� ����������
	if (sqlite3_open("my_cosy_database.dblite", &db))
		std::cerr << "������ ��������/�������� ��: " << sqlite3_errmsg(db) << std::endl;
	else if (sqlite3_exec(db, SQL_SELECT, select_callback, NULL, &err))
	{
		std::cerr << "������ SQL: " << err << std::endl;
		sqlite3_free(err);
	}

	// ��������� ����������
	sqlite3_close(db);
}

int main()
{
	sqlite3 *db = 0; // ����� ������� ���������� � ��
	char *err = 0;
	// ��������� ����������
	if (sqlite3_open("my_cosy_database.dblite", &db))
		std::cerr << "������ ��������/�������� ��: " << sqlite3_errmsg(db) << std::endl;

	writeToBase(db);

	readFromBase();

	return 0;
}