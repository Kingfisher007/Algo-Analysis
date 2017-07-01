#pragma once

#include "SingletonCounters.h"

class Object
{
public:
	Object(int n = 0);
	Object(const Object& rhs);
	const Object& operator=(const Object& rhs);
	bool operator>(const Object& rhs);
	bool operator<(const Object& rhs);
	void swap(Object& rhs);
	operator int();
	int getVal();

private:
	int m_val;
	SingletonCounters* m_SCounter = SingletonCounters::get();
};
