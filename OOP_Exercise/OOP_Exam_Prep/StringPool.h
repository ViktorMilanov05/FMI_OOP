#pragma once
class StringPool {
	struct StringRecords {
		char* str = nullptr;
		unsigned refCount = 0;
	};
	StringRecords* strings;
	unsigned count;
	unsigned cap;

	void free();
	void copyFrom(const StringPool& other);
	void moveFrom(StringPool& other);

	void resize(unsigned newCap);
	void removeRecord(unsigned ind);
	void allocateRecord(const char* str);
	int findRecordIndex(const char* str) const;

public:
	StringPool();
	//StringPool(const StringPool& other) = delete;
	//StringPool(StringPool&& other) = delete;
	//StringPool& operator=(const StringPool& other) = delete;
	//StringPool& operator=(StringPool&& other) = del;
	//~StringPool() = delete;

	void remove(const char* str);
	const char* add(const char* str);
};
