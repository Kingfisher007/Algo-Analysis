#include "SingletonCounters.h"
#include "Object.h"

	Object::Object(int n)
		:m_val(n)
	{
		m_SCounter = SingletonCounters::get();
	}

	Object::Object(const Object& rhs)
		:m_val(rhs.m_val)
	{
		//Update the counter
		m_SCounter.incrementAssignments();
	}

	const Object& Object::operator=(const Object& rhs)
	{
		m_val = rhs.m_val;
		//Update the counter
		m_SCounter.incrementAssignments();
		return *this;
	}

	bool Object::operator>(const Object& rhs)
	{
		//Update the counter
		m_SCounter.incrementComparisons();
		return m_val > rhs.m_val;
	}

	bool Object::operator<(const Object& rhs)
	{
		//Update the counter
		m_SCounter.incrementComparisons();
		return m_val < rhs.m_val;
	}

	void Object::swap(Object& rhs)
	{
		m_SCounter.incrementSwaps();
		Object temp(rhs);
		rhs = (*this);
		*this = temp;
	}

	Object::operator int()
	{
		return m_val;
	}

	int Object::getVal()
	{
		return m_val;
	}
