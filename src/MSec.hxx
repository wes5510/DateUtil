#ifndef MSEC_H
#define MSEC_H

#include "DateType.hxx"

class MSec : public DateType
{
	private:
		static const char SYMBOL;
	public:
		static const int MAX;
		virtual ~MSec();
		virtual bool verify(const int val);
};

#endif
