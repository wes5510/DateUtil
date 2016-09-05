#ifndef DATE_TYPE_H
#define DATE_TYPE_H

class DateType
{
	public:
		virtual ~DateType();
		virtual bool verify(const int val) = 0;
};

#endif
