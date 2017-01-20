#pragma once
class Super {
public:
	Super() = default;
	virtual void powerOverwhelming();
	virtual void somethingOnYourMine();
	~Super() = default;
};

class Sub :public Super {
public:
	Sub() = default;
	virtual void somethingOnYourMine();
	~Sub() = default;
};