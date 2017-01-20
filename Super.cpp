#include "Super.h"
#include <iostream>

void Super::somethingOnYourMine() {
	std::cout << " something on your mine" << std::endl;
}

void Sub::somethingOnYourMine() {
	std::cout << " zeaglings behind the minerals" << std::endl;
}
/*
void Sub::somethingOnYourMine() {
	std::cout << "no virtual in sc2" << std::endl;
}*/