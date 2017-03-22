#include "stdafx.h"
#include "learn.h"


Learn::Learn()
{
	sqlite3_open("learn.db", &db);
}

void Learn::create_tabel()
{
	sql = "CREATE TABLE IF NOT EXISTS learn(key CHAR(200),value CHAR(200))";
	sqlite3_exec(db, sql, 0, 0, 0);
}

void Learn::insert(char * key, char * value)
{
	std::string s_key(key), s_value(value);
	std::string s_sql = "INSERT INTO learn(key,value) VALUES ('";
	s_sql += s_key;
	s_sql += "','";
	s_sql += s_value;
	s_sql += "')";
	sqlite3_exec(db, s_sql.c_str(), 0, 0, 0);
}

bool Learn::find_by_key(char * key, char *& value)
{
	sql = "SELECT key,value FROM learn";
	sqlite3_get_table(db, sql, &result, &row, &column, &errmesg);
	int index = column;
	for (int i = 0; i < row; i++) {
		char *k = result[index];
		if (strcmp(key, k) == 0) {
			value = result[index + 1];
			return true;
		}
		index += column;
	}
	return false;
}

void Learn::update(char * key, char * value)
{
	std::string s_key(key), s_value(value), s_sql;
	s_sql = "UPDATE learn SET value = '" + s_value + "' WHERE key = '" + s_key + "'";
	std::cout << s_sql.c_str();
	sqlite3_exec(db, s_sql.c_str(), 0, 0, 0);
}


Learn::Learn(char * db_name)
{
	sqlite3_open(db_name, &db);
}

Learn::~Learn()
{
	sqlite3_close(db);
}
