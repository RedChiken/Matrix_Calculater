#include "SpreadSheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

SpreadSheetCell::SpreadSheetCell() : mvalue(0), mString("") {

}

SpreadSheetCell::SpreadSheetCell(double init) {
	this->setValue(init);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src) : 
	mString(src.mString){
	mvalue = src.mvalue;
}

SpreadSheetCell & SpreadSheetCell::operator=(const SpreadSheetCell & rhs)
{
	if (rhs.getString() == this->getString() && rhs.mvalue == this->mvalue) {

	}
	return *this;
}

SpreadSheetCell::~SpreadSheetCell() {

}

void SpreadSheetCell::setValue(double invalue) {
	this->mvalue = invalue;
	mString = doubleToString(mvalue);
}

double SpreadSheetCell::getValue() const {
	return this->mvalue;
}

void SpreadSheetCell::setString(string instring) {
	this->mString = instring;
	mvalue = stringToDouble(mString);
}

string SpreadSheetCell::getString() const {
	return this->mString;
}

string SpreadSheetCell::doubleToString(double inValue) const {
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadSheetCell::stringToDouble(string inString) const {
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof()) {
		return 0;
	}
	return temp;
}
