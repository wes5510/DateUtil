#ifndef MIN_H
#define MIN_H

#include "DateType.hxx"

class Min : public DateType
{
	public:
		static const char SYMBOL;
		static const int MAX;
		virtual ~Min();
		virtual bool verify(const int val);
};

#endif
