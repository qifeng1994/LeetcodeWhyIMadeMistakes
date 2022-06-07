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

	//转换函数，必须是类方法，不能指定返回类型，不能有参数
	operator int()const;
	operator double()const;
};
#endif // !STONE
