#include "stdafx.h"
#include "message.h"

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("");
	return 0;
}
message::message(int ac, int type, int64_t id,const char * mes)
{
	//判断消息类型

	this->type = type;
	if (type == 0)
		this->qqid = id;
	else if (type == 1)
		this->groupid = id;

	this->ac = ac;

	//消息分块
	this->mes = mes;
	string temp_mes(mes);
	this->mes_block = split(mes, " ");

	//消息判断
	jude();
	deal_message();
}

message::message()
{
}

message::~message()
{
}

mes_code message::jude()
{
	if (mes_block[0]== "学习" && mes_block.size() == 3) {
		m_mes_code = learn;
		return learn;
	}
	if (mes_block[0] == "应用" && mes_block.size() == 2) {
		m_mes_code = learn;
		return app;
	}
	
	m_mes_code = other;
	return other;
}

void message::deal_message()
{
	switch (m_mes_code) {
	case learn:
		deal_learn();
		break;
	case app:
		break;
	case learned:
		break;
	case other:
		break;
	}
}

void message::deal_learn()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc = sqlite3_open("learn.db",&db);
	char *sql = "CREATE TABLE IF NOT EXISTS learn(key char(200),value char(200))";
	sqlite3_exec(db, sql,0,0,0);
	char lear[100];
	strcpy_s(lear, mes_block[1].c_str());
	CQ_sendPrivateMsg(ac, qqid, lear);
}
