#include<iostream>
using namespace std;
#include"Header.h"

Stone::Stone(double pounds)
{
	stn = int(pounds) / pds_per_stn;
	pds_left = int(pounds) / pds_per_stn + (pounds - int(pounds));
	pds = pounds;
}

Stone::Stone(int stone, double pounds)
{
	stn = stone;
	pds_left = pounds;
	pds = stn * pds_per_stn + pounds;
}

Stone::Stone()
{
	stn = pds_left = pds = 0;
}

Stone::~Stone()
{

}

void Stone::show_pounds()const
{
	cout << pds << " pounds\n";
}

void Stone::show_stone()const
{
	cout << stn << " stone, " << pds_left << " pounds\n";
}

Stone::operator int()const
{
	return int(pds + 0.5);
}

Stone::operator double()const
{
	return pds;
}