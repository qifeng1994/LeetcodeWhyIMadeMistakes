#ifndef operatorr
#define operatorr
class Time
{
private:
	int min;
	int hour;
public:
	Time();
	Time(int m, int h);
	Time operator + (Time& t);
	void show();
};
#endif // !operatorr

