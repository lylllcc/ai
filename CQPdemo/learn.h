#pragma once
class Learn
{
private:
	sqlite3 *db;
	char *sql;
	char **result, *errmesg;
	int row, column;
public:
	Learn(char *db_name);
	Learn();
	void create_tabel();
	void insert(char *key, char *value);
	bool find_by_key(char *key, char* &value);
	void update(char *key, char* value);

	~Learn();
};

