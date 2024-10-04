#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma warning( disable : 4996)
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_DAY = 24 * 3600;

class Time {
	unsigned seconds = 0;
	bool validateAndSet(unsigned upper, unsigned lower, unsigned newValue, unsigned oldValue, unsigned multiplier) {
		if (newValue >= lower && newValue <= upper)
		{
			(seconds -= oldValue * multiplier) += newValue * multiplier;
			return true;
		}
		return false;
	}
public:
	Time() = default;
	Time(unsigned hours, unsigned minutes, unsigned seconds) {
		setHours(hours);
		setMinutes(minutes);
		setSeconds(minutes);
	}
	unsigned getHours() const {
		return seconds / SECONDS_IN_HOUR;
	}
	unsigned getMinutes() const {
		return (seconds / SECONDS_IN_MINUTE) % 60;
	}
	unsigned getSeconds() const {
		return seconds % 60;
	}
	bool setHours(unsigned hours) {
		return validateAndSet(23, 0, hours, getHours(), SECONDS_IN_HOUR);
	}
	bool setMinutes(unsigned minutes) {
		return validateAndSet(59, 0, minutes, getMinutes(), SECONDS_IN_MINUTE);
	}
	bool setSeconds(unsigned seconds) {
		return validateAndSet(59, 0, seconds, getSeconds(), 1);
	}
	void tick() {
		++seconds %= SECONDS_IN_DAY;
	}
	void serialize(std::ostream& os) const
	{
		os << setw(2) << setfill('0') << getHours() << ":"
			<< setw(2) << setfill('0') << getMinutes() << ":"
			<< setw(2) << setfill('0') << getSeconds() << std::endl;
	}
};


//int main()
//{
//	Time t(1, 22, 33);
//
//	t.setMinutes(30);
//	t.setSeconds(0);
//
//	t.serialize(cout);
//	t.tick();
//	t.serialize(cout);
//}
