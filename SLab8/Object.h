#pragma once
#include <string>
using namespace std;

class Object
{
public:
	Object(void) {}
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual string Get_name() = 0;
	virtual ~Object(void) {}
};