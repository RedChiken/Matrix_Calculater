#ifndef __SPREADSHEETCELL__
#include "SpreadSheetCell.h"
#include <iostream>
#include "Super.h"
#include <string>
#include <cstdio>
#include <cstdarg>
#include "matrix.h"
#endif // !__SPREADSHEETCELL__

using namespace std;


int main() {
	Matrix a(3, 3), b(4, 4);
	for (int i = 0; i < 9; i++) {
		a.setValue(i % 3, i / 3, i);
	}
	for (int i = 0; i < 16; i++) {
		b.setValue(i / 4, i % 4, i);
	}
	a.printValue();
	b.printValue();

	Matrix c(b);
	c.resize(3);
	a.resize(4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a.setValue(i, j, 3 * i + j - 12);
			c.setValue(j, i, 2 * j + i - 6);
		}
	}
	c.printValue();
	a.printValue();
	
	Matrix d = c * a, e = a * c;
	d.printValue();
	e.printValue();
	return 0;
}