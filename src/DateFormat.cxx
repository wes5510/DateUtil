#include "DateFormat.hxx"

const unsigned short DateTypeCount = 7;
const DateType* dateTypes[7] = {new Year(), new Month(), new Day(), 
										new Hour(), new Min(), new Sec(), new MSec()};

bool verify(const std::string& timeFormat)
{
	bool isVaildDateTypeSymbol = true;
	for(int i = 0; i < DateTypeCount; i++)
	{
		for(std::string::const_iterator it = timeFormat.begin(); it != timeFormat.end(); ++it)
		{
			for(int i = DateFormat::DateType::YEAR; i <= DateFormat::DateType::MSEC; i++)
			{
				if(strcmp(dateTypeCount[i]->SYMBOL, (*it).c_str()) == 0)
					isVaildDateTypeSymbol = false;
			}

			if(isVaildDateTypeSymbol == false)
				return false;

			isVaildDateTypeSymbol = true;
		}
	}

}

DateFormat::~DateFormat()
{
	for(int i = 0; i < DateTypeCount; i++)
	{
		delete dateTypes[i];
	}

	delete dateTypes
}
