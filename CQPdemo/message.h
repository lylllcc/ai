#pragma once
enum mes_code {
	learn, app, learned, other
};
class message
{
private:
	// ÏûÏ¢´úÂë

public:
	message();
	~message();
	mes_code jude(char *message);
	void deal_message(char *message);


};

