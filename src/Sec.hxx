#ifndef SEC_H
#define SEC_H

#include "DateType.hxx"

class Sec : public DateType
{
	public:
		static const char SYMBOL;
		static const int MAX;
		virtual ~Sec();
		virtual bool verify(const int val);
};

#endif
