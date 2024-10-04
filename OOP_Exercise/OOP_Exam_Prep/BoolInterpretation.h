class BoolInterpret {
	char values[26];
public:
	void set(char ch,bool val);
	bool operator()(char ch) const;
	void reduceByMask(unsigned mask);
	unsigned getTrueCount() const;
};