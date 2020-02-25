#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <string>
#include <array>
class HugeInteger
{
public:
	HugeInteger(long = 0); // conversion/default constructor if no param you get a default = 0
	HugeInteger(const std::string&); // cant use : using namespace std in header files.

	// addition operator HugeInteger + HugeInteger
	HugeInteger add(const HugeInteger &); // dont need to have variable names in class file.

	// subtraction operator
	//HugeInteger subtract(const HugeInteger&);

	// test if HugeInteger is less than this
	bool isLessThan(const HugeInteger &) const;

	// tests if HugeInteger is greater than
	bool isGreaterThan(const HugeInteger &) const;

	bool isEqualTo(const HugeInteger &) const;

	bool isNotEqualTo(const HugeInteger &) const;

	void input(const std::string&);
	void output() const; // class will already have data , const so you dont change data.
private:
	std::array<short, 40> integer; // 40 element array of digits.
};
#endif

