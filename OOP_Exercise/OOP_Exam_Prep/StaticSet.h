#include <cstdint>
constexpr unsigned MAX_NUMBER = 1023;
constexpr unsigned NUMBERS_COUNT = 1024;
constexpr unsigned BUCKET_SIZE = sizeof(uint8_t) * 8;
constexpr unsigned BUCKETS_COUNT = NUMBERS_COUNT / BUCKET_SIZE + 1;

class StaticSet {
	uint8_t buckets[BUCKETS_COUNT]{ 0 };
	unsigned getBucket(unsigned n) const;
	unsigned getBit(unsigned n) const;
public:
	StaticSet() = default;
	void add(unsigned n);
	void remove(unsigned n);
	bool contains(unsigned n) const;
	void print() const;

	friend StaticSet unionOfSets(const StaticSet& lhs, const StaticSet& rhs);
	friend StaticSet intersectOfSets(const StaticSet& lhs, const StaticSet& rhs);
};
