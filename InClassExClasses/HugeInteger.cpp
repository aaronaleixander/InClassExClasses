#include "HugeInteger.h"
#include <iostream>
#include <cstdlib>
#include <array>

using namespace std; // this code wont be copied into any other file

// constructor
HugeInteger::HugeInteger(long value) {
	for (size_t i = 0; i < 40; ++i) {
		integer[i] = 0;
	}
	for (int i = 39; value != 0 && i >= 0; --i) { // terminate for loop if value hits 0
		// strip off digits one by one and place into indexes.
		integer[i] = static_cast<short>(value % 10); // mod takes precedence before casting to short.
		value /= 10;
	}
}


HugeInteger::HugeInteger(const std::string& valStr) {
	input(valStr);
}

// Addition operator HugeInteger + HugeInteger
HugeInteger HugeInteger::add(const HugeInteger & op2) { // op2 = operand 2
	HugeInteger result; // calls no arg constuctor and sets them all to 0.

	short carry = 0;
	for (int i = 39; i >= 0; --i) {
		result.integer[i] = carry + integer[i] + op2.integer[i];
		if (result.integer[i] > 9) {
			carry = result.integer[i] / 10;
			result.integer[i] %= 10;
		} 
		else {
			carry = 0;
		}
	}
	return result;
}

// checks if less than
bool HugeInteger::isLessThan(const HugeInteger& op2)const {
	for (int i = 0; i < 40; ++i) {
		if (integer[i] > op2.integer[i]) {
			return false;
		} 
		else if (integer[i] < op2.integer[i]) {
			return true;
		}
		return false;
	}
}

// checks if greater than
bool HugeInteger::isGreaterThan(const HugeInteger& op2)const {
	for (int i = 0; i < 40; ++i) {
		if (integer[i] < op2.integer[i]) {
			return false;
		}
		else if (integer[i] > op2.integer[i]) {
			return true;
		}
		return false;
	}
}

bool HugeInteger::isEqualTo(const HugeInteger& op2) const {
	return !isLessThan(op2) && !isGreaterThan(op2);
}

bool HugeInteger::isNotEqualTo(const HugeInteger& op2) const {
	return !isEqualTo(op2);
}

void HugeInteger::input(const std::string& valStr) {
	for (size_t i = 0; i < 40; ++i) {
		integer[i] = 0;
	}
	int length = valStr.size();
	for (int i = 40 - length; i < 40; ++i) {
		integer[i] = static_cast<short> (valStr[i - 40 + length] - '0'); // as i increments
	}
}

void HugeInteger::output() const {
	// skip leading zeros
	size_t i = 0;
	for (; i < 40 && integer[i] == 0; ++i) {
		// no operation, we are skipping these zeros.
	}
	if (i == 0) {
		cout << 0;
	}
	else {
		for (; i < 40; ++i) {
			cout << integer[i];
		}
	}
}
