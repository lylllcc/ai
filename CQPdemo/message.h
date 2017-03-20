#pragma once
#include "stdafx.h"
enum mes_code {
	learn, app, learned, other
};
class message
{
private:
	const char *mes;
	int64_t qqid,groupid;
	std::vector<std::string> mes_block;
	int type;
	mes_code m_mes_code;
	int ac;

public:
	//type 0 私聊消息  1 群消息
	message(int ac,int type, int64_t id,const char *mes);
	message();
	~message();
	mes_code jude();
	void deal_message();
	void deal_learn();


};

