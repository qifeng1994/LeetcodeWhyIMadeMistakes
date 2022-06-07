#pragma once
#ifndef STONE
#define STONE

class Stone
{
private:
	static const int pds_per_stn = 14;
	int stn;
	double pds_left;
	double pds;
public:
	Stone(double);
	Stone(int, double);
	Stone();
	~Stone();

	void show_pounds()const;
	void show_stone()const;

	//ת���������������෽��������ָ���������ͣ������в���
	operator int()const;
	operator double()const;
};
#endif // !STONE
