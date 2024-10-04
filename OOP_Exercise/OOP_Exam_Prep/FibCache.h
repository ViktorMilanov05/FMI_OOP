#pragma once
constexpr unsigned N = 100;

class FibCache {
	unsigned values[N];
	unsigned nullValue;;
public:
	FibCache(unsigned nullValue);
	void add(unsigned key, unsigned value);
	bool contains(unsigned key);
	unsigned getValue(unsigned key);
};
