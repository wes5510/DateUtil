#ifndef DAY_H
#define DAY_H

#include "DateType.hxx"

class Day : public DateType
{
	public:
		static const char SYMBOL;
		static const int MAX;
		virtual ~Day();
		virtual bool verify(const int val);
};

#endif
