//P11
//composition表示has-a关系
//设计模式 adapter 适配器模式

//composition by reference表示两个类通过指针相连。指针指向类的实现。

//inheritance表示is-a-kind-of关系

//P12 虚函数

//设计模式：template method 用子类调用父类的方法
//class CDocument
//{
//public:
//	OnFileOpen();
//	virtual Serialize() {} //空的虚函数
//};
//
//CDocument::OnFileOpen()
//{
//	//...
//	Serialize();
//	//...
//}
//
//class CMyDoc :public CDocument
//{
//public:
//	virtual Serialize(){}
//};
//
//main()
//{
//	CMyDoc myDoc;
//	myDoc.OnFileOpen();
//}

//设计模式 observer or Publish/subscribe 观察者模式：delegation+inheritance

//P13
//设计模式 composite
//class Component
//{
//private:
//	int value;
//public:
//	Component(int val) { value = val; }
//	virtual void add(Component*){} //空的虚函数
//};
//
//class Primitive :public Component
//{
//public:
//	Primitive(int val):Component(val){}
//};
//
//class Composite :public Component
//{
//private:
//	vector<Component*> c; //composite类可以放component对象
//public:
//	Composite(int val) :Component(val) {}
//	void add(Component* elem) { c.push_back(elem); } //实现了委托
//};

//设计模式 prototype 没听懂
