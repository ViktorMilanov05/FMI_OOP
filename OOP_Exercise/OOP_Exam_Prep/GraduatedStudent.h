class GraduatedStudent {
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	char quote[31] = "";

	void copyFrom(const GraduatedStudent& other);
	void moveFrom(GraduatedStudent&& other);
	void free();
public:
	GraduatedStudent() = default;
	GraduatedStudent(const char* name, const int* grades, size_t count, const char* quote);
	GraduatedStudent(const GraduatedStudent& other);
	GraduatedStudent(GraduatedStudent&& other);
	GraduatedStudent& operator=(const GraduatedStudent& other);
	GraduatedStudent& operator=(GraduatedStudent&& other);
	~GraduatedStudent();

	const char* getName() const;
	const int* getGrades() const;
	size_t getGradesCount() const;
	const char* getQuote() const;

	void setName(const char* name);
	void setGrades(const int* grades, size_t count);
	void setQuote(const char* quote);
};
