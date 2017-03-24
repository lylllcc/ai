#include "stdafx.h"
#include "message.h"


message::message(int ac, int64_t id,const char * mes)
{
	

	this->qqid = id;
	this->ac = ac;
	this->groupid = -1;

	//��Ϣ�ֿ�
	this->mes = mes;
	std::string temp_mes(mes);
	this->mes_block = split(mes, " ");

}

message::message(int ac, int64_t groupid, int64_t qqid, const char * mes)
{
	this->ac = ac;
	this->groupid = groupid;
	this->qqid = qqid;
	this->mes = mes;

	//��Ϣ�ֿ�
	this->mes = mes;
	std::string temp_mes(mes);
	this->mes_block = split(mes, " ");
	
}

message::message()
{
}

message::~message()
{
}

mes_code message::jude()
{
	if (mes_block[0]== "ѧϰ" && mes_block.size() == 3) {
		m_mes_code = learn;
		return learn;
	}
	if (mes_block.size() == 1) {
		Learn l;
		std::string temp;
		if (l.find_by_key(mes_block[0], temp)) {
			m_mes_code = learned;
			return learned;
		}
			
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
	case learned:
		deal_learned();
		break;
	case other:
		break;
	}
}

void message::deal_learn()
{

	Learn l;
	l.create_tabel();

	std::string key = mes_block[1],value = mes_block[2],temp;
	//ѧϰ����
	if (l.find_by_key(key, temp)) {
		l.update(key, value);
	}
	//û��ѧϰ��
	else {
		l.insert(key, value);
	}

	std::string learn_str = "�Ҽ�ס\"" + key + "\"�Ļظ��ˡ�";

	//std::cout << "ѧϰ";
	if (groupid == -1) {
		CQ_sendPrivateMsg(ac, qqid, learn_str.c_str());
	}else
	{
		CQ_sendGroupMsg(ac, groupid, learn_str.c_str());
	}
	//system("pause");
	
}

void message::deal_learned()
{
	Learn l;
	l.create_tabel();
	std::string learned;
	l.find_by_key(mes_block[0], learned);
	if (groupid == -1) {
		CQ_sendPrivateMsg(ac, qqid, learned.c_str());
	}
	else {
		CQ_sendGroupMsg(ac, groupid, learned.c_str());
	}
		
	//std::cout << learned;
	//system("pause");

}
