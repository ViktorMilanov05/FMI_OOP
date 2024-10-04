#include "DynamicSet.h"
#include <iostream>
void DynamicSet::free()
{
	delete[] buckets;
	buckets = nullptr;
	n = 0;
	bucketsCount = 0;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
	buckets = new uint8_t[other.bucketsCount];
	for (size_t i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
	n = other.n;
	bucketsCount = other.bucketsCount;
}

void DynamicSet::moveFrom(DynamicSet&& other)
{
	buckets = other.buckets;
	other.buckets = nullptr;
	n = other.n;
	bucketsCount = other.bucketsCount;

}

DynamicSet::DynamicSet() : DynamicSet(0)
{
}

DynamicSet::DynamicSet(unsigned n)
{
	bucketsCount = n / bucket_Size + 1;
	this->n = n;
	buckets = new uint8_t[bucketsCount]{ 0 };
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet::DynamicSet(DynamicSet&& other)
{
	moveFrom(std::move(other));
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicSet& DynamicSet::operator=(DynamicSet&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

void DynamicSet::add(unsigned n)
{
	if (n > this->n)
		return;
	unsigned bitInd = n % bucket_Size;
	unsigned bucketInd = n / bucket_Size;
	uint8_t mask = 1 << bitInd;
	buckets[bucketInd] |= mask;
}

void DynamicSet::remove(unsigned n)
{
	if (n > this->n)
		return;
	unsigned bitInd = n % bucket_Size;
	unsigned bucketInd = n / bucket_Size;
	uint8_t mask = 1 << bitInd;
	mask = ~mask;
	buckets[bucketInd] &= mask;
}

bool DynamicSet::contains(unsigned n) const
{
	if (n > this->n)
		return false;
	unsigned bitInd = n % bucket_Size;
	unsigned bucketInd = n / bucket_Size;
	uint8_t mask = 1 << bitInd;
	return buckets[bucketInd] & mask;
}

void DynamicSet::print() const
{
	for (size_t i = 0; i < n; i++)
	{
		if (contains(i))
			std::cout << i << " ";
	}
}

DynamicSet unionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet result(std::max(lhs.n, rhs.n));
	unsigned minBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (size_t i = 0; i < minBuckets; i++)
	{
		result.buckets[i] = (lhs.buckets[i] | rhs.buckets[i]);
	}
	const DynamicSet& maxSet = lhs.bucketsCount >= rhs.bucketsCount ? lhs : rhs;
	for (size_t i = minBuckets; i < maxSet.bucketsCount; i++)
	{
		result.buckets[i] = maxSet.buckets[i];
	}
	return result;
}

DynamicSet intersectOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet result(std::min(lhs.n, rhs.n));
	unsigned minBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (size_t i = 0; i < minBuckets; i++)
	{
		result.buckets[i] = (lhs.buckets[i] & rhs.buckets[i]);
	}
	return result;
}
