#ifndef MONTH_H
#define MONTH_H

#include "DateType.hxx"

class Month : public DateType
{
	private:
		static const char SYMBOL;
	public:
		static const int MAX;
		virtual ~Month();
		virtual bool verify(const int val);
};

#endif
