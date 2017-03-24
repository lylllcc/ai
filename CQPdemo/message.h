#pragma once
#include "stdafx.h"
enum mes_code {
	learn, learned, other
};
class message
{
private:
	const char *mes;
	int64_t qqid,groupid;
	std::vector<std::string> mes_block;
	mes_code m_mes_code;
	int ac;

public:
	//Ë½ÁÄÏûÏ¢
	message(int ac, int64_t qqid,const char *mes);
	message(int ac, int64_t groupid,int64_t qqid, const char *mes);
	message();
	~message();
	mes_code jude();
	void deal_message();
	void deal_learn();
	void deal_learned();


};

