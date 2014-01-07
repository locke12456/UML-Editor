#pragma once
class Mode
{
public:
	Mode(void);
	~Mode(void);
	virtual void generate() = 0;
	virtual void modify() = 0;
	virtual void contact() = 0;
};

