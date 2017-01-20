#pragma once
#include <string>
using std::string;

class SpreadSheetCell {
public:
	friend string;
	SpreadSheetCell();
	SpreadSheetCell(double initialValue);
	SpreadSheetCell(const SpreadSheetCell &src);
	SpreadSheetCell& operator=(const SpreadSheetCell& rhs);
	~SpreadSheetCell();
	void setValue(double inValue);
	double getValue() const;
	void setString(string inString);
	string getString() const;
protected:
	string doubleToString(double inValue) const;
	double stringToDouble(string inString) const;
	double mvalue;
	string mString;
};