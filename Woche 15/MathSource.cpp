#include <iostream>
#include <assert.h>
#include "MyString.h"
#include "StringView.h"

class MathInterpretation {
public:
	void set(char ch, float value) {
		assert(ch >= 'a' && ch <= 'z');

		values[ch - 'a'] = value;
	}

	float operator()(char ch) const {
		assert(ch >= 'a' && ch <= 'z');

		return values[ch - 'a'];
	}

private:
	float values[26]{ 0 };
};

class MathExpression {
public:
	MathExpression() = default;

	MathExpression(const MathExpression&) = delete;
	MathExpression& operator=(const MathExpression&) = delete;

	virtual ~MathExpression() = default;

	virtual float eval(const MathInterpretation& mi) const = 0;
	virtual void populateValues(MathInterpretation& mi) const = 0;

	virtual MathExpression* clone() const = 0;	
};

//a to z
class Variable : public MathExpression {
public:
	Variable(char ch) : ch(ch) {}

	float eval(const MathInterpretation& mi) const override {
		return mi(ch);
	}

	void populateValues(MathInterpretation& mi) const override {
		mi.set(ch, 1);
	}

	MathExpression* clone() const override {
		return new Variable(ch);
	}

private:
	char ch;
};

//!
class UnaryOperation : public MathExpression {
public:
	UnaryOperation(MathExpression* opr) : opr(opr) {}

	void populateValues(MathInterpretation& mi) const override {
		opr->populateValues(mi);
	}

	~UnaryOperation() {
		delete opr;
	}

protected:
	MathExpression* opr = nullptr;
};

class Oppositor : public UnaryOperation {
public:
	Oppositor(MathExpression* opr) : UnaryOperation(opr) {}

	float eval(const MathInterpretation& mi) const override {
		return opr->eval(mi) * (-1);
	}

	MathExpression* clone() const override {
		return new Oppositor(opr->clone());
	}
};

//+, -, *, /
class BinaryOperation : public MathExpression {
public:
	BinaryOperation(MathExpression* lhs, MathExpression* rhs) 
		: lhs(lhs), rhs(rhs) {}

	void populateValues(MathInterpretation& mi) const override {
		lhs->populateValues(mi);
		rhs->populateValues(mi);
	}

	~BinaryOperation() {
		delete lhs;
		delete rhs;
	}

protected:
	MathExpression* lhs = nullptr;
	MathExpression* rhs = nullptr;
};

class PlusOperator : public BinaryOperation {
public:
	PlusOperator(MathExpression* lhs, MathExpression* rhs)
		: BinaryOperation(lhs,rhs) {}

	float eval(const MathInterpretation& mi) const override {
		return lhs->eval(mi) + rhs->eval(mi);
	}

	MathExpression* clone() const override {
		return new PlusOperator(lhs->clone(), rhs->clone());
	}
};

class MinusOperator : public BinaryOperation {
public:
	MinusOperator(MathExpression* lhs, MathExpression* rhs)
		: BinaryOperation(lhs, rhs) {}

	float eval(const MathInterpretation& mi) const override {
		return lhs->eval(mi) - rhs->eval(mi);
	}

	MathExpression* clone() const override {
		return new MinusOperator(lhs->clone(), rhs->clone());
	}
};

class MultiplyOperator : public BinaryOperation {
public:
	MultiplyOperator(MathExpression* lhs, MathExpression* rhs)
		: BinaryOperation(lhs, rhs) {}

	float eval(const MathInterpretation& mi) const override {
		return lhs->eval(mi) * rhs->eval(mi);
	}

	MathExpression* clone() const override {
		return new MultiplyOperator(lhs->clone(), rhs->clone());
	}
};

class DevideOperator : public BinaryOperation {
public:
	DevideOperator(MathExpression* lhs, MathExpression* rhs)
		: BinaryOperation(lhs, rhs) {}

	float eval(const MathInterpretation& mi) const override {
		return lhs->eval(mi) / rhs->eval(mi);
	}

	MathExpression* clone() const override {
		return new DevideOperator(lhs->clone(), rhs->clone());
	}
};

MathExpression* mathExpressionFactory(StringView str)
{
	str = str.substr(1, str.length() - 2); //remove the first and the last brackets

	if (str.length() == 1)
		return new Variable(str[0]);

	unsigned count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		else if (count == 0)
		{
			switch (str[i])
			{
			case '!': return new Oppositor(mathExpressionFactory(str.substr(i + 1, str.length() - i - 1)));
			case '+': return new PlusOperator(mathExpressionFactory(str.substr(0, i)), mathExpressionFactory(str.substr(i + 1, str.length() - i - 1)));
			case '-': return new MinusOperator(mathExpressionFactory(str.substr(0, i)), mathExpressionFactory(str.substr(i + 1, str.length() - i - 1)));
			case '*': return new MultiplyOperator(mathExpressionFactory(str.substr(0, i)), mathExpressionFactory(str.substr(i + 1, str.length() - i - 1)));
			case '/': return new DevideOperator(mathExpressionFactory(str.substr(0, i)), mathExpressionFactory(str.substr(i + 1, str.length() - i - 1)));
			}
		}
	}
	throw std::invalid_argument("Invalid expression!");
}

class MathExpressionWrapper {
public:
	MathExpressionWrapper(const MyString& str) {
		mathTree = mathExpressionFactory(str);

		mathTree->populateValues(mi);
	}

	MathExpressionWrapper(const MathExpressionWrapper& other) {
		copyFrom(other);
	}

	MathExpressionWrapper& operator=(const MathExpressionWrapper& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}

		return *this;
	}

	MathExpressionWrapper(MathExpressionWrapper&& other) noexcept{
		moveFrom(std::move(other));
	}

	MathExpressionWrapper& operator=(MathExpressionWrapper&& other) noexcept{
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}

		return *this;
	}

	float eval(const MathInterpretation& mi) {
		return mathTree->eval(mi);
	}

	~MathExpressionWrapper() {
		free();
	}

private:
	void free() {
		delete mathTree;
		mathTree = nullptr;
	}

	void copyFrom(const MathExpressionWrapper& other) {
		mi = other.mi;
		mathTree = other.mathTree->clone();
	}

	void moveFrom(MathExpressionWrapper&& other) {
		mi = std::move(other.mi);
		mathTree = other.mathTree;
		other.mathTree = nullptr;
	}

	MathInterpretation mi;
	MathExpression* mathTree = nullptr;
};

int main()
{
	MathExpressionWrapper mew("((!((x)*(y)))-(!(z)))");

	MathInterpretation mi;

	mi.set('x', 1);
	mi.set('y', 3.33);
	mi.set('z', 69);

	std::cout << mew.eval(mi);

	return 0;
}