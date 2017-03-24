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

void Learn::insert(std::string  key, std::string value)
{
	std::string s_sql = "INSERT INTO learn(key,value) VALUES ('";
	s_sql += key;
	s_sql += "','";
	s_sql += value;
	s_sql += "')";
	sqlite3_exec(db, s_sql.c_str(), 0, 0, 0);
}

bool Learn::find_by_key(std::string  key, std::string& value)
{
	sql = "SELECT key,value FROM learn";
	sqlite3_get_table(db, sql, &result, &row, &column, &errmesg);
	int index = column;
	for (int i = 0; i < row; i++) {
		char *k = result[index];
		if (strcmp(key.c_str(), k) == 0) {
			value = result[index + 1];
			return true;
		}
		index += column;
	}
	return false;
}

void Learn::update(std::string  key, std::string value)
{
	std::string  s_sql;
	s_sql = "UPDATE learn SET value = '" + value + "' WHERE key = '" + key + "'";
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
