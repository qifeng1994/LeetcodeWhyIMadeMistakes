#pragma once

#ifndef ABSTRACT
#define ABSTRACT
#include <string>
using namespace std;
class Organism //把生物类理解为一个抽象基类
{
public:
	virtual void EatFood() = 0; //基类至少包括一个纯虚函数
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
