#pragma once

class Answer
{
private:
	char* _answer = nullptr;
	bool _isCorrect = false;

public:
	Answer() = default;
	Answer(const char* answer, const bool* const isCorrect);

	Answer(const Answer& other);
	Answer& operator=(const Answer& other);

	Answer(Answer&& other) noexcept;
	Answer& operator=(Answer&& other) noexcept;

	~Answer();

	void setAnswer(const char* answer);
	void setIsCorrect(bool isCorrect);

	const char* getAnswer() const;
	bool getIsCorrect() const;

private:
	void free();
	void copyFrom(const Answer& other);
	void moveFrom(Answer&& other);
};
