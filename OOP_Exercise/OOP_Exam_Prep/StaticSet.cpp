#include "StaticSet.h"
#include <iostream>

unsigned StaticSet::getBucket(unsigned n) const
{
    return n / BUCKET_SIZE;
}

unsigned StaticSet::getBit(unsigned n) const
{
    return n % BUCKET_SIZE;
}

void StaticSet::add(unsigned n)
{
    if (n > MAX_NUMBER)
        return;
    unsigned bucketInd = getBucket(n);
    unsigned bitInd = getBit(n);

    uint8_t mask = 1 << bitInd;
    buckets[bucketInd] |= mask;
}

void StaticSet::remove(unsigned n)
{
    if (n > MAX_NUMBER)
        return;
    unsigned bucketInd = getBucket(n);
    unsigned bitInd = getBit(n);

    uint8_t mask = 1 << bitInd;
    mask = ~mask;
    buckets[bucketInd] &= mask;
}

bool StaticSet::contains(unsigned n) const
{
    if (n > MAX_NUMBER)
        return false;
    unsigned bucketInd = getBucket(n);
    unsigned bitInd = getBit(n);

    uint8_t mask = 1 << bitInd;
    return (buckets[bucketInd] & mask) != 0;
}

void StaticSet::print() const
{
    for (size_t i = 0; i < MAX_NUMBER; i++)
    {
        if (contains(i))
            std::cout << i << " ";
    }
}

StaticSet unionOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
    StaticSet s;
    for (size_t i = 0; i < BUCKETS_COUNT; i++)
    {
        s.buckets[i] = (lhs.buckets[i] | rhs.buckets[i]);
    }
    return s;
}

StaticSet intersectOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
    StaticSet s;
    for (size_t i = 0; i < BUCKETS_COUNT; i++)
    {
        s.buckets[i] = (lhs.buckets[i] & rhs.buckets[i]);
    }
    return s;
}
