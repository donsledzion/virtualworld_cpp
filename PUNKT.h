#pragma once
#include <iostream>
class	PUNKT
{

public:
	PUNKT(short, short);
	PUNKT();
	~PUNKT();

	short getX();
	short getY();
	PUNKT getWspolrzedne();

	void setX(short _x);
	void setY(short _y);
	void setWspolrzedne(PUNKT _location);

	PUNKT operator+(PUNKT& prawy)
	{
		return PUNKT(this->x + prawy.getX(), this->y + prawy.getY());
	}

	friend std::ostream& operator<<(std::ostream& os, PUNKT _punkt)
	{
		os << _punkt.getX() << " , " << _punkt.getY();
		return os;
	}

private:
	short x;
	short y;

};