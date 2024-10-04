#include "BoolInterpretation.h"
#include <exception>

void BoolInterpret::set(char ch,bool val)
{
	if (ch < 'a' && ch > 'z')
		throw std::exception();
	values[ch - 'a'] = val;
}

bool BoolInterpret::operator()(char ch) const
{
	if (ch < 'a' && ch > 'z')
		throw std::exception();
	return values[ch - 'a'];
}

void BoolInterpret::reduceByMask(unsigned mask)
{
	for (size_t i = 25; i >= 0; i--)
	{
		if (values[i]) {
			if (mask % 2 == 0) {
				values[i] = false;
			}
			mask /= 2;
		}
	}
}

unsigned BoolInterpret::getTrueCount() const
{
	unsigned count = 0;
	for (size_t i = 0; i < 26; i++)
	{
		if (values[i])
			count++;
	}
	return count;
}
