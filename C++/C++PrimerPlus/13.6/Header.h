#pragma once

#ifndef ABSTRACT
#define ABSTRACT
#include <string>
using namespace std;
class Organism //�����������Ϊһ���������
{
public:
	virtual void EatFood() = 0; //�������ٰ���һ�����麯��
};

class Animal :public Organism
{
public:
	string AnimalName;
	Animal(string Aname);
	virtual void EatFood();
};

class Plant :public Organism
{
public:
	string PlantName;
	Plant(string Pname);
	virtual void EatFood();
};


#endif // !ABSTRACT
