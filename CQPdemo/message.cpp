#include "stdafx.h"
#include "message.h"


message::message()
{
}


message::~message()
{
}

mes_code message::jude(char * message)
{
	return learn;
}

void message::deal_message(char * message)
{
	mes_code code = this->jude(message);
	switch (code) {
	case learn:
		break;
	case app:
		break;
	case learned:
		break;
	case other:
		break;
	}
}
