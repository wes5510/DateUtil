#ifndef YEAR_H
#define YEAR_H

#include "DateType.hxx"

class Year : public DateType
{
	public:
		static const char SYMBOL;
		static const int MAX;
		virtual ~Year();
		virtual bool verify(const int val);
};

#endif
