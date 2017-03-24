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
	void insert(std::string  key, std::string value);
	bool find_by_key(std::string  key, std::string& value);
	void update(std::string  key, std::string value);

	~Learn();
};

