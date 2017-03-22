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
	std::string temp_mes(mes);
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

	Learn l;
	l.create_tabel();
	char key[1024],*value;
	strcpy_s(key, mes_block[1].c_str());

	//学习过的
	if (l.find_by_key(key, value)) {

	}
	//没有学习过
	else {

	}

	CQ_sendPrivateMsg(ac, qqid, lear);
}
