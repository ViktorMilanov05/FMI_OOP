#include <cstdint>
class DynamicSet {
	uint8_t* buckets = nullptr;
	unsigned n = 0;
	const unsigned bucket_Size = 8 * sizeof(uint8_t);
	unsigned bucketsCount = 0;

	void free();
	void copyFrom(const DynamicSet& other);
	void moveFrom(DynamicSet&& other);
public:
	DynamicSet();
	DynamicSet(unsigned n);
	DynamicSet(const DynamicSet& other);
	DynamicSet(DynamicSet&& other);
	DynamicSet& operator=(const DynamicSet& other);
	DynamicSet& operator=(DynamicSet&& other);
	~DynamicSet();

	void add(unsigned n);
	void remove(unsigned n);
	bool contains(unsigned n) const;
	void print() const;

	friend DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet intersectOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
};

class SetByCriteria : public DynamicSet {
public:
	SetByCriteria(unsigned n, bool(*cr)(unsigned)) : DynamicSet(n) {
		for (size_t i = 0; i < n; i++)
		{
			if (cr(i))
				add(i);
		}
	}
};