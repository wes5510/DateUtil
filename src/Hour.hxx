#ifndef HOUR_H
#define HOUR_H

#include "DateType.hxx"

class Hour : public DateType
{
	public:
		static const char SYMBOL;
		static const int MAX;
		virtual ~Hour();
		virtual bool verify(const int val);
};

#endif
